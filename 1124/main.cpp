#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> vis;

int main()
{
    freopen("input1124.txt", "r", stdin);
    int m, n, s;
    cin >> m >> n >> s;
    cin.ignore();
    if(m < s){
        cout << "Keep going..." << endl;
        return 0;
    }
    vector<string> arr(m+1);
    for(int i = 1; i <= m; ++i){
        getline(cin, arr[i]);
    }
    int cnt = 0;
    for(int i = s;i <= m; ++i){
        if(cnt % n == 0){
            if(vis[arr[i]] == 0){
                cout << arr[i] << endl;
                cnt = 0;
                vis[arr[i]] = 1;
            }
            else{
                cnt--;
            }

        }
        cnt++;
    }
    return 0;
}
