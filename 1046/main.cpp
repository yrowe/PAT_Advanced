#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int Dis[maxn];
int main(){
    freopen("input1046.txt", "r", stdin);
    Dis[1] = 0;
    int n, tmp;
    int sum = 0;
    cin >> n;
    for(int i = 2; i <= n; ++i){
        //循环读不带最后一个
        cin >> tmp;
        sum += tmp;
        Dis[i] = sum;
    }
    cin >> tmp;
    sum += tmp;
    int m;
    cin >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        if(v1 > v2)
            swap(v1, v2);
        int sum1 = Dis[v2] - Dis[v1];
        if(sum - sum1 < sum1)
            cout << sum - sum1 << endl;
        else
            cout << sum1 << endl;
    }
    return 0;
}
