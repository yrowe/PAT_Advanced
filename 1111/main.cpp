#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <ctime>

using namespace std;

const int INF = 0x3fffffff;
const int maxn = 505;
int GT[maxn][maxn];
int GD[maxn][maxn];
int source, destination;
vector<int> pre[maxn];
int d[maxn];
int n, m;
bool vis[maxn];

void DijkstraD(int s){
    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);
    d[s] = 0;
    for(int i = 0; i < n; ++i){
        int u = -1, MIN = INF;
        for(int j = 0;j < n; ++j){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) break;
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if(vis[v] == false && GD[u][v] != INF){
                if(d[u] + GD[u][v] < d[v]){
                    d[v] = d[u] + GD[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u] + GD[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> path, tempPath;
int optValue = INF;

void DFSD(int v){
    if(v == source){
        tempPath.push_back(v);
        int value = 0;
        for(int i = tempPath.size()-1; i > 0; --i){
            int id = tempPath[i], idNext = tempPath[i-1];
            value += GT[id][idNext];
        }
        if(value < optValue){
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
    }
    tempPath.push_back(v);
    for(int i = 0;i < pre[v].size(); ++i){
        DFSD(pre[v][i]);
    }
    tempPath.pop_back();
}

vector<int> pre2[maxn];
void Dijkstra2(int s){
    fill(d, d+maxn, INF);
    fill(vis, vis+maxn, false);
    d[s] = 0;
    for(int i = 0;i < n; ++i){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; ++j){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;

        for(int v = 0; v < n; ++v){
            if(vis[v] == false && GT[u][v] != INF){
                if(d[u] + GT[u][v] < d[v]){
                    d[v] = d[u] + GT[u][v];
                    pre2[v].clear();
                    pre2[v].push_back(u);
                }else if(d[u] + GT[u][v] == d[v]){
                    pre2[v].push_back(u);
                }
            }
        }
    }
}

vector<int> tempPath2, Path2;
int cntNode = INF;

void DFS2(int v){
    if(v == source){
        tempPath2.push_back(v);
        int num = 0;
        for(int i = tempPath2.size()-1; i > 0; --i){
            num++;
        }
        if(num < cntNode){
            cntNode = num;
            Path2 = tempPath2;
        }
        tempPath2.pop_back();
        return;
    }
    tempPath2.push_back(v);
    for(int i = 0;i < pre2[v].size(); ++i){
        DFS2(pre2[v][i]);
    }
    tempPath2.pop_back();

}

int main()
{
    srand(time(NULL));
    freopen("input1111.txt", "r", stdin);

    fill(GT[0], GT[0]+maxn*maxn, INF);
    fill(GD[0], GD[0]+maxn*maxn, INF);
    scanf("%d %d", &n, &m);
    while(m--){
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        if(c == 1){
            GD[a][b] = d;
            GT[a][b] = e;
        }
        else{
            GD[a][b] = GD[b][a] = d;
            GT[a][b] = GT[b][a] = e;
        }
    }
    scanf("%d %d", &source, &destination);
    DijkstraD(source);
    DFSD(destination);

    Dijkstra2(source);
    DFS2(destination);

    int minD = 0;
    for(int i = path.size()-1; i > 0; --i){
        int id = path[i], idnext = path[i-1];
        minD += GD[id][idnext];
    }

    int minTime = 0;
    for(int i = Path2.size()-1; i > 0; --i){
        int id = Path2[i], idnext = Path2[i-1];
        minTime += GT[id][idnext];
    }

    if(path == Path2){
        cout << "Distance = " << minD << "; Time = " << minTime << ": ";
        for(int i = Path2.size()-1; i >= 0; --i){
            cout << Path2[i];
            if(i != 0){
                cout << " -> ";
            }
            else{
                cout << endl;
            }
        }
    }
    else{
        cout << "Distance = " << minD << ": ";
        for(int i = path.size()-1; i >= 0; --i){
            cout << path[i];
            if(i != 0){
                cout << " -> ";
            }
            else{
                cout << endl;
            }
        }
        cout << "Time = " << minTime << ": ";
        for(int i = Path2.size()-1; i >= 0; --i){
            cout << Path2[i];
            if(i != 0){
                cout << " -> ";
            }
            else{
                cout << endl;
            }
        }
    }
    return 0;
}
