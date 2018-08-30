#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct node{
    int v;
    bool isRed;
    node *lchild, *rchild;
};

int getBlackNum(node* p, bool &flg){
    if(p == NULL){
        return 1;
    }
    int n1 = getBlackNum(p->lchild, flg);
    int n2 = getBlackNum(p->rchild, flg);
    if(flg == false)
        return -1;
    if(n1 != n2){
        flg = false;
        return -1;
    }
    if(p->isRed == false) n1++;
    return n1;
}

node* newNode(int v){
    node* p = new node;
    p->v = abs(v);
    if(v < 0)
        p->isRed = true;
    else
        p->isRed = false;
    p->lchild = p->rchild = NULL;
    return p;
}

void Insert(node* &p, int v){
    if(p == NULL){
        p = newNode(v);
        return;
    }
    if(abs(v) < p->v){
        Insert(p->lchild, v);
    }
    else{
        Insert(p->rchild, v);
    }
}

const int maxn = 35;
int arr[maxn];

node* create(int n){
    node* root = NULL;
    for(int i = 0;i < n; ++i){
        Insert(root, arr[i]);
    }
    return root;
}

bool redChild = false;

void DFS(node* p){
    if(redChild == true)
        return;
    if(p == NULL)
        return;
    if(p->isRed == true){
        if(p->lchild != NULL && p->lchild->isRed == true)
            redChild = true;
        if(p->rchild != NULL && p->rchild->isRed == true)
            redChild = true;
    }
    DFS(p->lchild);
    DFS(p->rchild);
}


int main()
{
    freopen("input1135.txt", "r", stdin);
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        node* root = create(n);
        if(root->isRed == true){
            cout << "No" << endl;
            continue;
        }
        redChild = false;
        DFS(root);
        if(redChild == true){
            cout << "No" << endl;
            continue;
        }
        bool flg = true;
        getBlackNum(root, flg);
        if(flg == false){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }

    return 0;
}
