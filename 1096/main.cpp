#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    freopen("input1096.txt", "r", stdin);
    ll ansStart, ansLen = 0;
    ll n;
    cin >> n;
    ll sqr = (ll)sqrt(1.0*n);
    for(ll i = 2; i <= sqr; ++i){
        int tmp = 1, j = i;
        while(1){
            tmp *= j;
            if(n%tmp != 0) break;
            if(j - i + 1 > ansLen){
                ansLen = j - i + 1;
                ansStart = i;
            }
            j++;
        }

    }
    if(ansLen == 0){
        cout << 1 << endl;
        cout << n << endl;
    }
    else{
        cout << ansLen << endl;
        for(int i = 0;i < ansLen; ++i){
            cout << ansStart + i;
            if(i < ansLen - 1)
                cout << "*";
        }
    }
    return 0;
}
