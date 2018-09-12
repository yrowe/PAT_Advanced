#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1005;
int arr[maxn];
int n, m;

bool isTopo(set<int> a[]){
    bool flg = true;
    for(int i = 0;i < n; ++i){
        int tmp = arr[i];
        if(a[tmp].size() != 0){
            flg = false;
            break;
        }
        for(int j = 1;j <= n; ++j){
            set<int>::iterator result = a[j].find(tmp);
            if(result != a[j].end()){
                a[j].erase(result);
            }
        }
    }
    return flg;
}

set<int> aa[maxn], bb[maxn];

int main()
{
    freopen("input1146.txt", "r", stdin);

    cin >> n >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        aa[v2].insert(v1);
    }
    int k;
    cin >> k;
    int fi = 0;
    for(int i = 0;i < k; ++i){
        for(int j = 1;j <= n; ++j){
            bb[j] = aa[j];
        }
        for(int j = 0;j < n; ++j){
            cin >> arr[j];
        }
        bool flg = isTopo(bb);
        if(flg == false){
            if(fi == 0){
                cout << i;
                fi = 1;
            }
            else{
                cout << " " << i;
            }
        }
    }
    return 0;
}
