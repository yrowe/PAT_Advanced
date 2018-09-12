#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> post1, post2, level1, level2;
int n;
vector<int> arr;

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

node* create(){
    node* p = NULL;
    for(int i = 0;i < n; ++i){
        Insert(p, arr[i]);
    }
    return p;
}



void DFS(node* p, vector<int> &v){
    if(p == NULL) return;
    DFS(p->lchild, v);
    DFS(p->rchild, v);
    v.push_back(p->v);
}

void BFS(node* p, vector<int> &v){
    queue<node*> q;
    q.push(p);
    while(!q.empty()){
        node* u = q.front();
        q.pop();
        v.push_back(u->v);
        if(u->lchild != NULL)
            q.push(u->lchild);
        if(u->rchild != NULL)
            q.push(u->rchild);
    }
}

int main()
{
    freopen("8.txt", "r", stdin);
    cin >> n;
    arr.resize(n);
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }
    node* root = create();
    DFS(root, post1);
    BFS(root, level1);

    root = NULL;
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }
    root = create();
    DFS(root, post2);
    BFS(root, level2);

    if(post1 == post2 && level1 == level2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    for(int i = 0;i < post1.size(); ++i){
        if(i != post1.size()-1){
            cout << post1[i] << " ";
        }
        else{
            cout << post1[i] << endl;
        }
    }
    for(int i = 0;i < level1.size(); ++i){
        if(i != level1.size()-1){
            cout << level1[i] << " ";
        }
        else{
            cout << level1[i] << endl;
        }
    }

    return 0;
}
