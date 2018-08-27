#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int v;
    node *lchild, *rchild;
    int level;
};

const int maxn = 35;
int In[maxn];
int Post[maxn];

node* create(int postL, int postR, int inL, int inR){
    if(postL > postR)
        return NULL;
    node* p = new node;
    p->v = Post[postR];
    int value = p->v;
    int k;
    for(k = inL; k <= inR; ++k){
        if(In[k] == value) break;
    }
    int left = k - inL;
    p->lchild = create(postL, postL+left-1, inL, k-1);
    p->rchild = create(postL+left, postR-1, k+1, inR);
    return p;
}

vector<int> ans[maxn];
int maxLevel = -1;

void BFS(node* root){
    queue<node*> q;
    root->level = 1;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        ans[tmp->level].push_back(tmp->v);
        if(tmp->level > maxLevel) maxLevel = tmp->level;
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
    freopen("input1127.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> In[i];
    }
    for(int i = 0;i < n; ++i){
        cin >> Post[i];
    }
    node* root = create(0, n-1, 0, n-1);
    BFS(root);
    int num = 0;
    for(int i = 1; i <= maxLevel; ++i){
        if(i % 2 == 0){
            for(int j = 0;j < ans[i].size(); ++j){
                cout << ans[i][j];
                num++;
                if(num != n){
                    cout << " ";
                }
                else{
                    cout << endl;
                }
            }
        }
        else{
            for(int j = ans[i].size()-1; j >= 0; --j){
                cout << ans[i][j];
                num++;
                if(num != n){
                    cout << " ";
                }
                else{
                    cout << endl;
                }
            }
        }

    }
    return 0;
}
