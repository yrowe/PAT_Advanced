#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int v, dis;
    node(int _v,int _dis){
        v = _v;
        dis = _dis;
    }
};

const int MAXV = 505;
const int INF = 0x3fffffff;
int n;
vector<node> adj[MAXV];
vector<int> pre[MAXV];
bool inq[MAXV] = {false};
int d[MAXV];
int num[MAXV] = {0};

bool SPFA(int s){
    queue<int> Q;
    fill(d, d+MAXV, INF);
    Q.push(s);
    inq[s] = true;
    d[s] = 0;
    num[s]++;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int j = 0;j < adj[u].size(); ++j){
            int v = adj[u][j].v, dis = adj[u][j].dis;
            if(d[u] + dis < d[v]){
                pre[v].clear();
                pre[v].push_back(u);
                d[v] = d[u]+dis;
                if(inq[v] == false){
                    inq[v] = true;
                    Q.push(v);
                    num[v]++;
                    if(num[v] >= n) return false;
                }
            }
            else if(d[u] + dis == d[v]){
                pre[v].push_back(u);
            }
        }
    }
}


int m, c1, c2;
int hands[MAXV] = {0};

vector<int> path, tempPath;
int numPath = 0;
int maxHands = -1;

void DFS(int ss){
    tempPath.push_back(ss);
    if(ss == c1){
        numPath++;
        int tmpHands = 0;
        for(int i = 0;i < tempPath.size(); ++i){
            tmpHands += hands[tempPath[i]];
        }
        if(tmpHands > maxHands){
            maxHands = tmpHands;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0;i < pre[ss].size(); ++i){
        DFS(pre[ss][i]);
    }
//    for(auto ii: pre[ss]){
//        DFS(ii);
//    }
    tempPath.pop_back();
    return;
}

int main()
{
    freopen("input1003.txt", "r", stdin);
    cin >> n >> m >> c1 >> c2;
    for(int i = 0;i < n; ++i){
        cin >> hands[i];
    }
    while(m--){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        adj[v1].push_back(node(v2, wt));
        adj[v2].push_back(node(v1, wt));
    }
    SPFA(c1);
    DFS(c2);
    cout << numPath << " " << maxHands << endl;
    return 0;
}


