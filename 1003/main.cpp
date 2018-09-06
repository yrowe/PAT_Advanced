#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node{
    int v, dis;
    Node(int _v, int _dis): v(_v), dis(_dis){}
};

const int MAXV = 505;
const int INF = 0x3fffffff;
vector<Node> Adj[MAXV];
int n, d[MAXV], num[MAXV];
bool inq[MAXV];
vector<int> pre[MAXV];

bool SPFA(int s){
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d+MAXV, INF);
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    num[s]++;
    d[s] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int j = 0;j < Adj[u].size(); ++j){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if(d[u] + dis < d[v]){
                pre[v].clear();
                pre[v].push_back(u);
                d[v] = d[u] + dis;
                if(!inq[v]){
                    Q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= n) return false;
                }
            }
            else if(d[u] + dis == d[v]){
                pre[v].push_back(u);
            }
        }
    }
    return true;
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
        Adj[v1].push_back(Node(v2, wt));
        Adj[v2].push_back(Node(v1, wt));
    }
    SPFA(c1);
    DFS(c2);
    cout << numPath << " " << maxHands << endl;
    return 0;
}
