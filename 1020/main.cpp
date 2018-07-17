#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;
const int maxn = 35;
int post[maxn], in[maxn];

struct node{
    int data;
    node *lchild, *rchild;
};

node* create(int inL,int inR,int postL,int postR){
    if(postL > postR) return NULL;
    node* Node = new node;
    Node->data = post[postR];
    int k;
    for(int i = inL; i <= inR; ++i){
        if(in[i] == post[postR]){
            k = i;
            break;
        }
    }
    int numLeft = k - inL;
    Node->lchild = create(inL, k-1, postL, postL+numLeft-1);
    Node->rchild = create(k+1, inR, postL+numLeft, postR-1);
    return Node;
}

int num = 0;

void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        if(num == 0){
            cout << tmp->data;
            num++;
        }
        else{
            cout << " " << tmp->data;
        }
        if(tmp->lchild != NULL) q.push(tmp->lchild);
        if(tmp->rchild != NULL) q.push(tmp->rchild);
    }
    cout << endl;
}


int main()
{
    freopen("input1020.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> post[i];
    }
    for(int i = 0;i < n;++i){
        cin >> in[i];
    }
    node* root = create(0, n-1, 0, n-1);
    BFS(root);
    return 0;
}
