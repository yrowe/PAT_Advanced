#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 205;
int G[maxn][maxn];


int main()
{
    freopen("input1122.txt", "r", stdin);
    vector<int> arr;
    fill(G[0], G[0]+maxn*maxn, 0);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    }
    int k;
    cin >> k;
    while(k--){
        int num, tmp;
        cin >> num;
        arr.clear();
        set<int> ss;
        for(int i = 0;i < num; ++i){
            cin >> tmp;
            arr.push_back(tmp);
        }
        if(num != n + 1){
            cout << "NO" << endl;
            continue;
        }
        if(arr[0] != arr[num-1]){
            cout << "NO" << endl;
            continue;
        }
        bool flg = false;

        for(int i = 0;i < num-1; ++i){
            ss.insert(arr[i]);
            if(G[arr[i]][arr[i+1]] != 1){
                flg = true;
                break;
            }
        }
        if(flg == true){
            cout << "NO" << endl;
            continue;
        }
        if(ss.size() == n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}
