#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 1005;
int inDegree[maxn] = {0};
vector<int> G[maxn];
int n, m;

vector<int> topoOrder;
int topoSort(){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0;i < n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){

        int u = q.top();
        topoOrder.push_back(u);
        q.pop();
        for(int i = 0;i < G[u].size(); ++i){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
    }
    return topoOrder.size();
}

int main()
{
    freopen("11.txt", "r", stdin);
    cin >> n >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        inDegree[v2]++;
    }
    int num = topoSort();
    if(num == n){
        cout << "YES" << endl;
        for(int i = 0;i < num; ++i){
            if(i != num-1){
                cout << topoOrder[i] << " ";
            }
            else{
                cout << topoOrder[i] << endl;
            }
        }
    }
    else{
        cout << "NO" << endl;
        cout << n - num << endl;
    }
    return 0;
}
