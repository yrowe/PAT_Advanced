#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int G[maxn][maxn];
bool vis[maxn] = {false};
int inDegree[maxn] = {0};
int n, m;

int ans[maxn];

void DFS(int num){
    if(num == n){
        for(int i = 0;i < n; ++i){
            if(i != n-1){
                cout << ans[i] << " ";
            }
            else{
                cout << ans[i] << endl;
            }
        }
        return;
    }
    for(int i = 1;i <= n; ++i){
        if(inDegree[i] == 0 && vis[i] == false){
            for(int j = 1;j <= n; ++j){
                if(G[i][j] == 1){
                    inDegree[j]--;
                }
            }
            vis[i] = true;
            ans[num] = i;
            DFS(num+1);
            for(int k = 1;k <= n; ++k){
                if(G[i][k] == 1){
                    inDegree[k]++;
                }
                vis[i] = false;
            }
        }
    }

}

int main(){
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        inDegree[v2]++;
    }
    DFS(0);
}
