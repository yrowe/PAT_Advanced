#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 10005;
int arr[maxn];
int q, n;
set<int> vis;

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
    for(int i = 0; i < n; ++i){
        Insert(p, arr[i]);
    }
    return p;
}

vector<int> pre, pre1, pre2;

node* root;

void findv(node* p, int v){
    if(p->v == v){
        pre.push_back(p->v);
        return;
    }
    if(v < p->v) findv(p->lchild, v);
    else findv(p->rchild, v);
    pre.push_back(p->v);
}

int main()
{
    freopen("input1143.txt", "r", stdin);
    //cin >> q >> n;
    scanf("%d %d", &q, &n);
    for(int i = 0;i < n; ++i){
        //cin >> arr[i];
        scanf("%d", &arr[i]);
        vis.insert(arr[i]);
    }
    root = create();
    while(q--){
        int n1, n2;
        //cin >> n1 >> n2;
        scanf("%d %d", &n1, &n2);
        if(vis.find(n1) == vis.end() && vis.find(n2) == vis.end()){
            printf("ERROR: %d and %d are not found.\n", n1, n2);
        }
        else if(vis.find(n1) == vis.end()){
            printf("ERROR: %d is not found.\n", n1);
        }
        else if(vis.find(n2) == vis.end()){
            printf("ERROR: %d is not found.\n", n2);
        }
        else{
            pre.clear();
            findv(root, n1);
            pre1 = pre;
            reverse(pre1.begin(), pre1.end());
            pre.clear();
            findv(root, n2);
            pre2 = pre;
            reverse(pre2.begin(), pre2.end());
            int i;
            bool flg = false;
            int l = min(pre1.size(), pre2.size());
            for(i = 0;i < l; ++i){
                if(pre1[i] != pre2[i]){
                    flg = true;
                    break;
                }
            }
            if(flg == true){
                printf("LCA of %d and %d is %d.\n", n1, n2, pre1[i-1]);
            }
            else{
                if(pre1.size() < pre2.size()){
                    printf("%d is an ancestor of %d.\n", n1, n2);
                }
                else{
                    printf("%d is an ancestor of %d.\n", n2, n1);
                }
            }
        }
    }
    return 0;
}
