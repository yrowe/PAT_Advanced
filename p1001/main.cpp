#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int v;
    node *lchild, *rchild;
};

node* newNode(int v){
    node* p = new node;
    p->v = v;
    p->lchild = p->rchild = NULL;
    return p;
}

void Insert(node* &p, int v){
    if(p == NULL){
        p = newNode(v);
        return;
    }
    if(v < p->v){
        Insert(p->lchild, v);
    }
    else{
        Insert(p->rchild, v);
    }
}

const int maxn = 100005;
int n;
int arr[maxn];

node* create(){
    node* p = NULL;
    for(int i = 0;i < n; ++i){
        Insert(p, arr[i]);
    }
    return p;
}

void BFS(node* p){
    int cnt = 0;
    queue<node*> q;
    q.push(p);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        cnt++;
        if(cnt != n){
            cout << tmp->v << " ";
        }
        else{
            cout << tmp->v << endl;
        }
        if(tmp->lchild != NULL){
            q.push(tmp->lchild);
        }
        if(tmp->rchild != NULL){
            q.push(tmp->rchild);
        }
    }
}

int main()
{
    freopen("1.txt","r", stdin);
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }
    node* root = create();
    BFS(root);
    return 0;
}
