#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1005;
int n, m;
vector<int> G[maxn];
int inDegree[maxn] = {0};
vector<int> topOrder;

bool topoSort(){
    priority_queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
            st.push_back(i);
        }
    }
    while(!q.empty()){
        int u = q.top();
        topOrder.push_back(u);
        q.pop();
        for(int i = 0;i < G[u].size(); ++i){
            int v = G[u][i];
            inDegree[v]--;
            T[u].push_back(v);
            if(inDegree[v] == 0){
                q.push(v);

            }
        }
    }
}


int main()
{
    freopen("inputtopo.txt", "r", stdin);
    cin >> n >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        inDegree[v2]++;
    }

    topoSort();
    return 0;
}
