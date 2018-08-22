#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct node{
    int value;
    node *lchild, *rchild;
};

node* newNode(int v){
    node* root = new node;
    root->value = v;
    root->lchild = root->rchild = NULL;
    return root;
}

void Insert(node* &root, int v){
    if(root == NULL){
        root = newNode(v);
        return;
    }
    if(v < root->value){
        Insert(root->lchild, v);
    }
    else{
        Insert(root->rchild, v);
    }
}

node* create(vector<int> &v){
    node* root = NULL;
    for(int i = 0; i < v.size(); ++i){
       Insert(root, v[i]);
    }
    return root;
}

vector<int> preOrder, imagePreOrder;

void DFS(node* p){
    preOrder.push_back(p->value);
    if(p->lchild != NULL) DFS(p->lchild);
    if(p->rchild != NULL) DFS(p->rchild);
}

void DFS2(node *p){
    imagePreOrder.push_back(p->value);
    if(p->rchild != NULL) DFS2(p->rchild);
    if(p->lchild != NULL) DFS2(p->lchild);
}

int cnt = 0;
void postOrder(node *p){
    if(p->lchild != NULL) postOrder(p->lchild);
    if(p->rchild != NULL) postOrder(p->rchild);
    if(cnt != 0){
        printf(" %d", p->value);
    }
    else{
        printf("%d", p->value);
    }
    cnt++;
}

void ImagePost(node *p){
    if(p->rchild != NULL) ImagePost(p->rchild);
    if(p->lchild != NULL) ImagePost(p->lchild);
    if(cnt != 0){
        printf(" %d", p->value);
    }
    else{
        printf("%d", p->value);
    }
    cnt++;
}

int main()
{
    freopen("input1043.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0;i < n; ++i){
        scanf("%d", &v[i]);
    }
    node* root = create(v);
    DFS(root);
    DFS2(root);
    if(preOrder == v){
        printf("YES\n");
        postOrder(root);
    }
    else if(imagePreOrder == v){
        printf("YES\n");
        ImagePost(root);
    }
    else{
        printf("NO\n");
    }
    return 0;
}
