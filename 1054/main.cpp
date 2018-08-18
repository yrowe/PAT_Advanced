#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<int, int> cnt;

int main()
{
    freopen("input1054.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;

    for(int j = 0;j < n; ++j){
        for(int i = 0;i < m; ++i){
            int tmp;
            cin >> tmp;
            cnt[tmp]++;
        }
    }
    for(auto i: cnt){
        if(i.second >= m*n/2)
            cout << i.first << endl;
    }
    return 0;
}
