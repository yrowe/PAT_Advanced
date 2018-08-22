#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 105;

struct Node{
    int lchild, rchild;
    int value;
}node[maxn];

int arr[maxn];

int cnt = 0;

void inOrder(int p){
    if(node[p].lchild != -1) inOrder(node[p].lchild);
    node[p].value = arr[cnt];
    cnt++;
    if(node[p].rchild != -1) inOrder(node[p].rchild);
}

int n;

void BFS(int p){
    queue<int> q;
    q.push(p);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        printf("%d", node[tmp].value);
        if(cnt != n-1){
            printf(" ");
        }
        else{
            printf("\n");
        }
        cnt++;
        if(node[tmp].lchild != -1) q.push(node[tmp].lchild);
        if(node[tmp].rchild != -1) q.push(node[tmp].rchild);
    }
}

int main()
{
    freopen("input1099.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0;i < n; ++i){
        scanf("%d %d", &node[i].lchild, &node[i].rchild);
    }
    for(int i = 0;i < n; ++i){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    inOrder(0);
    cnt = 0;
    BFS(0);
    return 0;
}
