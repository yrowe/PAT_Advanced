#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 50005;
int pre[maxn];
int In[maxn];

struct node{
    int v;
    node *lchild, *rchild;
};

int flg = false;
int ans;
void DFS(node* p){
    if(p == NULL)
        return;
    DFS(p->lchild);
    DFS(p->rchild);
    cout << p->v << endl;
    exit(0);
}

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR) return NULL;
    node* p = new node;
    p->v = pre[preL];
    int k;
    for(k = inL; k <= inR; ++k){
        if(In[k] == p->v) break;
    }
    int numLeft = k - inL;
    p->lchild = create(preL+1, preL+numLeft, inL, k-1);
    p->rchild = create(preL+numLeft+1, preR, k+1, inR);
    return p;
}

int main()
{
    freopen("input1138.txt", "r", stdin);
    int n;
    //cin >> n;
    scanf("%d", &n);
    for(int i = 0;i < n; ++i){
        //cin >> pre[i];
        scanf("%d", &pre[i]);
    }
    for(int i = 0;i < n; ++i){
        //cin >> In[i];
        scanf("%d", &In[i]);
    }
    node* root = create(0, n-1, 0, n-1);
    DFS(root);
    cout << ans << endl;
    return 0;
}
