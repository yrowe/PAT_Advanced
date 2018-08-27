#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int v;
    node *lchild, *rchild;
    int height;
};

node* newNode(int v){
    node* p = new node;
    p->lchild = p->rchild = NULL;
    p->height = 1;
    p->v = v;
    return p;
}

int getHeight(node *p){
    if(p == NULL) return 0;
    else return p->height;
}

void updateHeight(node *p){
    p->height = max(getHeight(p->lchild), getHeight(p->rchild)) + 1;
}

int getBalanceFactor(node *p){
    return getHeight(p->lchild) - getHeight(p->rchild);
}

void R(node* &p){
    node* temp = p->lchild;
    p->lchild = temp->rchild;
    temp->rchild = p;
    updateHeight(p);
    updateHeight(temp);
    p = temp;
}

void L(node* &p){
    node* temp = p->rchild;
    p->rchild = temp->lchild;
    temp->lchild = p;
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

const int maxn = 25;
int n;
int arr[maxn];

node* create(){
    node* root = NULL;
    for(int i = 0;i < n; ++i){
        Insert(root, arr[i]);
    }
    return root;
}

bool BFS(node* root){
    bool flg = false;
    queue<node*> q;
    q.push(root);
    int cnt = 1;
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        if(cnt != n){
            cout << tmp->v << " ";
        }
        else{
            cout << tmp->v << endl;
        }
        if(cnt <= n/2 && flg == false){
            if(tmp->lchild == NULL || tmp->rchild == NULL)
                flg = true;
        }
        if(cnt == n/2 && tmp->lchild != NULL && tmp->rchild == NULL)
            flg = false;
        cnt++;
        if(tmp->lchild != NULL){
            q.push(tmp->lchild);
        }
        if(tmp->rchild != NULL){
            q.push(tmp->rchild);
        }
    }
    return flg;
}

int main()
{
    freopen("input1123.txt", "r", stdin);
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }

    node* root = create();
    bool ans = BFS(root);
    if(ans == false){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
