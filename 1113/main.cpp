#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input1113.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0;i < n; ++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    if(n%2 == 0){
        printf("0 ");
        int ans = 0;
        for(int i = 0;i < n/2; ++i){
            ans += abs(v[i]-v[n-i-1]);
        }
        printf("%d\n", ans);
    }
    else{
        printf("1 ");
        int ans = 0;
        for(int i = 0;i < n/2; ++i){
            ans += abs(v[i]-v[n-i-1]);
        }
        ans += v[n/2];
        printf("%d\n", ans);
    }
    return 0;
}
