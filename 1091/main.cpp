#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int P[1300][130][65];
bool visit[1300][130][65] = {false};

int cnt = 0;
int m, n, l, t;

struct point{
    int x, y, z;
    point(int _x, int _y, int _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

bool judge(point pp){
    if(pp.x < 0 || pp.x >= m)
        return false;
    if(pp.y < 0 || pp.y >= n)
        return false;
    if(pp.z < 0 || pp.z >= l)
        return false;
    if(visit[pp.x][pp.y][pp.z] == true || P[pp.x][pp.y][pp.z] == 0)
        return false;

    return true;
}

int X[6] = {1,-1,0,0,0,0};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {0,0,0,0,1,-1};

void BFS(int i, int j, int k){
    queue<point> q;
    point tmp(i, j, k);
    q.push(tmp);
    while(!q.empty()){
        cnt++;
        tmp = q.front();
        q.pop();
        for(int ii = 0; ii < 6; ++ii){
            point tmp2(tmp.x + X[ii], tmp.y + Y[ii], tmp.z + Z[ii]);
            if(judge(tmp2)){
                q.push(tmp2);
                visit[tmp2.x][tmp2.y][tmp2.z] = true;
            }
        }

    }
}

int main()
{
    freopen("input1091.txt", "r", stdin);
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0;i < l; ++i){
        for(int j = 0;j < m; ++j){
            for(int z = 0; z < n; ++z){
                scanf("%d", &P[j][z][i]);
            }
        }
    }

    int blocks = 0;
    for(int i = 0;i < l; ++i){
        for(int j = 0;j < m; ++j){
            for(int z = 0; z < n; ++z){
                if(visit[j][z][i] == false && P[j][z][i] == 1){
                    cnt = 0;
                    visit[j][z][i] = true;
                    BFS(j, z, i);
                    if(cnt >= t){
                        blocks += cnt;
                    }
                }
            }
        }
    }
    cout << blocks << endl;
    return 0;
}
