#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
    int v, height;
    node *lchild, *rchild;
};

node *root;

node* newNode(int v){
    node* Node = new node;
    Node->v = v;
    Node->lchild = Node->rchild = NULL;
    Node->height = 1;
    return Node;
}

int getHeight(node *p){
    if(p == NULL) return 0;
    return p->height;
}

void updateHeight(node *p){
    p->height = max(getHeight(p->lchild), getHeight(p->rchild))+1;
}

int getBalanceFactor(node* p){
    return getHeight(p->lchild) - getHeight(p->rchild);
}

void L(node* &p){
    node* temp = p->rchild;
    p->rchild = temp->lchild;
    temp->lchild = p;
    updateHeight(p);
    updateHeight(temp);
    p = temp;
}

void R(node* &p){
    node* temp = p->lchild;
    p->lchild = temp->rchild;
    temp->rchild = p;
    updateHeight(p);
    updateHeight(temp);
    p = temp;
}

void Insert(node* &p, int v){
    if(p == NULL){
        p = newNode(v);
        return;
    }
    if(v < p->v){
        Insert(p->lchild, v);
        updateHeight(p);
        if(getBalanceFactor(p) == 2){
            if(getBalanceFactor(p->lchild) == 1){
                R(p);
            }
            else if(getBalanceFactor(p->lchild) == -1){
                L(p->lchild);
                R(p);
            }
        }

    }
    else{
        Insert(p->rchild, v);
        updateHeight(p);
        if(getBalanceFactor(p) == -2){
            if(getBalanceFactor(p->rchild) == -1){
                L(p);
            }
            else if(getBalanceFactor(p->rchild) == 1){
                R(p->rchild);
                L(p);
            }
        }
    }
}

int main()
{
    freopen("input1066.txt", "r", stdin);
    int n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v);
        Insert(root, v);
    }
    printf("%d\n", root->v);
    return 0;
}
