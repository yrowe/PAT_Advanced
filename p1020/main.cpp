#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node{
    int v, w;
    node(int _v, int _w){
        v = _v;
        w = _w;
    }
};

const int maxn = 1005;
int inDegree[maxn] = {0};
stack<int> topOrder;

vector<node> G[maxn];
int ve[maxn];
int vl[maxn];

int n, m;

int topoSort(){
    queue<int> q;
    for(int i = 0;i < n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        topOrder.push(u);
        q.pop();
        for(int i = 0;i < G[u].size(); ++i){
            int v = G[u][i].v;
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
            if(ve[u] + G[u][i].w > ve[v]){
                ve[v] = ve[u] +G[u][i].w;
            }
        }
    }
    return topOrder.size();
}

vector<int> C[maxn];
int Degree[maxn] = {0};

void criticalPath(){
    while(!topOrder.empty()){
        int u = topOrder.top();
        topOrder.pop();
        for(int i = 0;i < G[u].size(); ++i){
            int v = G[u][i].v, w = G[u][i].w;
            if(vl[v] - w < vl[u]){
                vl[u] = vl[v] - w;
            }
        }
    }


    for(int u = 0;u < n; ++u){
        for(int i = 0;i < G[u].size(); ++i){
            int v = G[u][i].v, w = G[u][i].w;
            int e = ve[u], l = vl[v] - w;
            if(e == l){
                C[u].push_back(v);
                Degree[v]++;
            }
        }
    }
    return;
}

vector<int> path;
void DFS(int v){
    path.push_back(v);
    if(C[v].size() == 0){
        for(int i = 0;i < path.size(); ++i){
            if(i != path.size()-1){
                cout << path[i] << "->";
            }
            else{
                cout << path[i] << endl;
            }
        }
        path.pop_back();
        return;
    }
    for(int i = 0;i < C[v].size(); ++i){
        DFS(C[v][i]);
    }
    path.pop_back();
}

int main()
{
    freopen("20.txt", "r", stdin);
    fill(ve, ve+maxn, 0);
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(node(b, c));
        inDegree[b]++;
    }
    int num = topoSort();
    if(num != n){
        cout << "NO " << n-num << endl;
        return 0;
    }
    int maxLength = -1;
    for(int i = 0;i < n; ++i){
        if(ve[i] > maxLength){
            maxLength = ve[i];
        }
    }
    fill(vl, vl+maxn, maxLength);
    cout << "YES " << maxLength << endl;
    criticalPath();
    for(int i = 0;i < n; ++i){
        sort(C[i].begin(), C[i].end());
    }
    for(int i = 0;i < n; ++i){
        if(Degree[i] == 0 && C[i].size() != 0){
            DFS(i);
        }
    }
    return 0;
}
