#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10010;
bool edge[maxn];
vector<int> v[maxn];

int main()
{
    freopen("input1134.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(i);
        v[v2].push_back(i);
    }
    int k;
    cin >> k;
    while(k--){
        fill(edge, edge+maxn, false);
        int num;
        cin >> num;
        while(num--){
            int p;
            cin >> p;
            for(int i = 0;i < v[p].size(); ++i){
                edge[v[p][i]] = true;
            }
        }
        bool flg = false;
        for(int i = 0;i < m; ++i){
            if(edge[i] == false){
                flg = true;
                break;
            }
        }
        if(flg){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
