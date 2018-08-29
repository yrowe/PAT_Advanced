#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

const int maxn = 10002;
const int INF = 0x3fffffff;
vector<int> G[maxn];
set<int> station;
vector<int> trans[maxn];

vector<int> pre[maxn];
int d[maxn];
bool vis[maxn];
void dijkstra(int s){
    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);
    d[s] = 0;
    for(auto i :station){
        int u = -1, MIN = INF;
        for(auto j :station){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < G[u].size(); ++v){
            if(vis[G[u][v]] == false){
                if(d[u] + 1 < d[G[u][v]]){
                    d[G[u][v]] = d[u] + 1;
                    pre[G[u][v]].clear();
                    pre[G[u][v]].push_back(u);
                }
                else if(d[u] + 1 == d[G[u][v]]){
                    pre[G[u][v]].push_back(u);
                }
            }
        }
    }
}

int st, ed;
vector<int> path, tempPath;

int minTans = 105;

void DFS(int v){
    if(v == st){
        tempPath.push_back(v);
        int cnt = 0;
        for(int i = 0; i < tempPath.size(); ++i){
            int id = tempPath[i];
            if(trans[id].size() > 1)
                cnt++;
        }
        if(cnt < minTans){
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0;i < pre[v].size(); ++i){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

struct stop{
    int s1, s2;
    friend bool operator < (stop a, stop b){
        if(a.s1 != b.s1)
            return a.s1 < b.s1;
        else
            return a.s2 < b.s2;
    }

    stop(){

    }
    stop(int _s1, int _s2){
        s1 = _s1;
        s2 = _s2;
    }
};

map<stop, int> line;


int main()
{
    freopen("input1131.txt", "r", stdin);
    int n;
    //cin >> n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        int m;
        //cin >> m;
        scanf("%d", &m);
        int id1, id2;
        //cin >> id1;
        scanf("%d", &id1);
        station.insert(id1);
        trans[id1].push_back(i);
        m--;
        while(m--){
            //cin >> id2;
            scanf("%d", &id2);
            line[stop(id1, id2)] = i;
            line[stop(id2, id1)] = i;
            station.insert(id2);
            trans[id2].push_back(i);
            G[id1].push_back(id2);
            G[id2].push_back(id1);
            id1 = id2;
        }


    }
    int k;
    cin >> k;
    while(k--){
        vector<int> outp;
        //cin >> st >> ed;
        scanf("%d %d", &st, &ed);
        path.clear();
        tempPath.clear();
        dijkstra(st);
        DFS(ed);
        //cout << path.size()-1 << endl;
        printf("%d\n", path.size()-1);
        reverse(path.begin(), path.end());
        int currentline = -1;

        for(int i = 0;i < path.size()-1; ++i){
            if(line[stop(path[i], path[i+1])] != currentline){
                if(outp.size() != 0){
                    //cout << "Take line#" << currentline << " from " << outp[0] << " to " << outp[outp.size()-1] << endl;
                    printf("Take Line#%d from %d to %d.\n", currentline, outp[0], outp[outp.size()-1]);
                }
                outp.clear();
                outp.push_back(path[i]);
                outp.push_back(path[i+1]);
                currentline = line[stop(path[i], path[i+1])];
            }
            else{
                outp.push_back(path[i+1]);
            }

        }

        if(outp.size() != 0){
            //cout << "Take line#" << currentline << " from " << outp[0] << " to " << outp[outp.size()-1] << endl;
            printf("Take Line#%d from %d to %d.\n", currentline, outp[0], outp[outp.size()-1]);
        }

    }
    return 0;
}
