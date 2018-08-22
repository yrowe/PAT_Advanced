#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int arr[maxn] = {0};
int node[maxn];
int n;
int cnt = 0;

void DFS(int p){
    if(p > n) return;
    DFS(p*2);
    node[p] = arr[cnt];
    cnt++;
    DFS(p*2+1);
}

int main()
{
    freopen("input1064.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    DFS(1);
    for(int i = 1; i <= n; ++i){
        printf("%d", node[i]);
        if(i != n) printf(" ");
        else printf("\n");
    }
    return 0;
}
