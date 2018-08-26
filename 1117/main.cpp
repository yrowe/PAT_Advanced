#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int arr[maxn];

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    freopen("input1117.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        scanf("%d", &arr[i]);
    }

    sort(arr+1, arr+n+1, cmp);
    int k;
    for(k = n; k > 0; --k){
        if(k < arr[k])
            break;
    }
    cout << k << endl;
    return 0;
}
