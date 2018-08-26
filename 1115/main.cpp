#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1010;
struct node{
    int v;
    node *rchild, *lchild;
    int level;
};

node* newNode(int v){
    node* root = new node;
    root->v = v;
    root->lchild = root->rchild = NULL;
    return root;
}

void Insert(node* &root, int v){
    if(root == NULL){
        root = newNode(v);
        return;
    }
    if(v <= root->v){
        Insert(root->lchild, v);
    }
    else{
        Insert(root->rchild, v);
    }
}

int n;
int arr[maxn];
node* r = NULL;

void create(){
    for(int i = 0; i < n; ++i){
        Insert(r, arr[i]);
    }
}

int maxLevel = -1;
int cnt[maxn] = {0};

void BFS(){
    queue<node*> q;
    q.push(r);
    r->level = 1;
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        if(tmp->level > maxLevel){
            maxLevel = tmp->level;
        }
        cnt[tmp->level]++;
        if(tmp->lchild != NULL){
            tmp->lchild->level = tmp->level + 1;
            q.push(tmp->lchild);
        }
        if(tmp->rchild != NULL){
            tmp->rchild->level = tmp->level + 1;
            q.push(tmp->rchild);
        }
    }
}

int main()
{
    freopen("input1115.txt", "r", stdin);
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }
    create();
    BFS();
    cout << cnt[maxLevel] << " + " << cnt[maxLevel-1] << " = " << cnt[maxLevel] + cnt[maxLevel-1] << endl;

    return 0;
}
