#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
	int v;
	Node *lchild,*rchild;
}*root;

const int maxn = 40;
int pre[maxn],post[maxn];

bool isUnique = true;

Node* create(int preL,int preR,int postL,int postR){
	if(preL > preR) return NULL;
	Node* node = new Node;
	node->v = pre[preL];
	node->lchild = NULL;
	node->rchild = NULL;
	if(preL == preR) return node;

	int k;
	for(k = preL + 1;k <= preR;++k){
		if(pre[k] == post[postR - 1]) break;
	}
	if(k - preL > 1){
        //k指向的是右子树的根结点， 减去1， 即其左子树结点个数+根（1个）
        //大于1， 说明左子树至少有一个结点。
		node->lchild = create(preL + 1,k - 1,postL,postL + k - preL - 2);
		node->rchild = create(k,preR,postL + k - preL - 1,postR - 1);
	}
	else{
		isUnique = false;
		node->rchild = create(k,preR,postL + k - preL - 1,postR - 1);
	}

	return node;
}

int cnt = 0,n;

void inOrder(Node* node){
	if(node == NULL) return;
	inOrder(node->lchild);
	if(cnt < n-1) cout << node->v << " ";
	else cout << node->v << endl;
	++cnt;
	inOrder(node->rchild);
}

int main(){
	freopen("input1119.txt","r",stdin);
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> pre[i];
	}

	for(int i = 0;i < n;++i){
		cin >> post[i];
	}
	root = create(0,n-1,0,n-1);

	if(isUnique){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
	inOrder(root);
}
