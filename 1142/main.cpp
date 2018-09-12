#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 205;
const int INF = 0x3fffffff;
int G[maxn][maxn];
bool vis[maxn];

int main()
{
    freopen("input1142.txt", "r", stdin);
    fill(G[0], G[0]+maxn*maxn, INF);
    int nv, ne;
    cin >> nv >> ne;
    while(ne--){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    }
    int k;
    cin >> k;
    while(k--){
        int tmp, num;
        cin >> num;
        fill(vis, vis+maxn, false);
        set<int> vertex;
        bool flg1 = false;
        while(num--){
            cin >> tmp;
            for(auto i :vertex){
                if(G[i][tmp] == INF){
                    flg1 = true;
                }
            }
            vis[tmp] = true;
            vertex.insert(tmp);
        }
        if(flg1){
            cout << "Not a Clique" << endl;
            continue;
        }
        int cnt = 0;
        flg1 = false;
        bool flg2 = false;
        for(auto i: vertex){
            for(int j = 1;j <= nv; ++j){
                if(vis[j] == false && G[i][j] == 1){
                    cnt = 0;
                    for(auto z: vertex){

                        if(G[j][z] == 1){
                            cnt++;
                        }
                        else{
                            flg1 = true;
                        }
                    }
                    vis[j] = true;
                }
                if(cnt == vertex.size()){
                    flg2 = true;
                    break;
                }
            }
            if(flg2)
                break;
        }
        if(flg2){
            cout << "Not Maximal" << endl;
        }
        else{
            cout << "Yes" << endl;
        }

    }
    return 0;
}
