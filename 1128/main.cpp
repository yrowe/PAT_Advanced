#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int G[maxn][maxn];
int col[maxn];
bool hashTable[maxn];

int main()
{
    freopen("input1128.txt", "r", stdin);
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        fill(G[0], G[0]+maxn*maxn, 0);
        fill(col, col+maxn, 0);
        fill(hashTable, hashTable+maxn, false);
        int row;
        for(int i = 1;i <= n; ++i){
            cin >> row;
            G[row][i] = 1;
            col[i] = row;
            hashTable[row] = true;
        }
        int ans = 0;
        for(int i = 1;i <= n; ++i){
            ans += hashTable[i];
        }
        if(ans != n){
            cout << "NO" << endl;
            continue;
        }

        bool flg = false;
        for(int i = 1;i <= n; ++i){
            int c1 = col[i], c2 = col[i];

            for(int j = i+1;j <= n; ++j){
                c1 = c1+1;
                c2 = c2-1;
                if(c1 > n && c2 < 1)
                    break;
                if(c1 <= n && G[c1][j] == 1){
                    flg = true;
                    break;
                }
                if(c2 >= 1 && G[c2][j] == 1){
                    flg = true;
                    break;
                }
            }
            if(flg == true){
                break;
            }
        }
        if(flg == true){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
