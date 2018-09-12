#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

struct node{
    int v;
    node *lchild, *rchild;
};

node* create(vector<int> &level, vector<int> &In){
    if(level.size() == 0){
        return NULL;
    }
    node* p = new node;
    p->v = level[0];
    int k;
    int num = In.size();
    for(k = 0;k < num; ++k){
        if(In[k] == p->v) break;
    }
    set<int> leftNode;
    vector<int> leftIn, leftLevel, rightIn, rightLevel;
    for(int i = 0;i < k; ++i){
        leftIn.push_back(In[i]);
        leftNode.insert(In[i]);
    }
    for(int i = k+1;i < num; ++i){
        rightIn.push_back(In[i]);
    }
    for(int i = 1;i < num; ++i){
        if(leftNode.find(level[i]) != leftNode.end()){
            leftLevel.push_back(level[i]);
        }
        else{
            rightLevel.push_back(level[i]);
        }
    }
    p->lchild = create(leftLevel, leftIn);
    p->rchild = create(rightLevel, rightIn);
    return p;
}

int n;
int cnt;

void preOrder(node* p){
    if(p == NULL) return;
    cnt++;
    if(cnt != n){
        cout << p->v << " ";
    }
    else{
        cout << p->v << endl;
    }
    preOrder(p->lchild);
    preOrder(p->rchild);
}

void postOrder(node *p){
    if(p == NULL) return;
    postOrder(p->lchild);
    postOrder(p->rchild);
    cnt++;
    if(cnt != n){
        cout << p->v << " ";
    }
    else{
        cout << p->v << endl;
    }
}

int main()
{
    freopen("D.txt", "r", stdin);
    vector<int> level, In;

    cin >> n;
    level.resize(n);
    In.resize(n);
    for(int i = 0;i < n; ++i){
        cin >> level[i];
    }
    for(int i = 0;i < n; ++i){
        cin >> In[i];
    }

    node* root = create(level, In);
    cnt = 0;
    preOrder(root);
    cnt = 0;
    postOrder(root);

    return 0;
}
