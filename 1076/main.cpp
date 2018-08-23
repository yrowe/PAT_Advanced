#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int G[maxn][maxn];
bool vis[maxn];
int n, l;

struct node{
    int level;
    int v;
    node(int _level, int _v){
        level = _level;
        v = _v;
    }
};

int BFS(int p){
    int cnt = 0;
    fill(vis, vis+maxn, false);
    queue<node> q;
    vis[p] = true;
    q.push(node(0, p));
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        for(int i = 1;i <= n; ++i){
            if(vis[i]==false && G[tmp.v][i]==1){
                if(tmp.level < l){
                    vis[i] = true;
                    q.push(node(tmp.level+1, i));
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    freopen("input1076.txt", "r", stdin);
    fill(G[0], G[0]+maxn*maxn, 0);
    scanf("%d %d", &n, &l);
    for(int i = 1;i <= n; ++i){
        int num;
        scanf("%d", &num);
        while(num--){
            int j;
            scanf("%d", &j);
            G[j][i] = 1;
        }
    }
    int k;
    scanf("%d", &k);
    while(k--){
        int query;
        scanf("%d", &query);
        int ans = BFS(query);
        cout << ans << endl;
    }
    return 0;
}
