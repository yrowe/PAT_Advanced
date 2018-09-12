#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
    freopen("10.txt", "r", stdin);
    int n;
    cin >> n;
    arr.resize(n);
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin()+n);
    if(n%2 == 0){
        cout << "0 ";
    }
    else{
        cout << "1 ";
    }

    long long ans1 = 0, ans2 = 0;
    for(int i = 0;i < n/2; ++i){
        ans1 += arr[i];
    }
    for(int i = n/2; i < n; ++i){
        ans2 += arr[i];
    }
    cout << ans2 - ans1 << endl;
    return 0;
}
