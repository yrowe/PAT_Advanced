#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input1008.txt", "r", stdin);
    int pre = 0;
    int now, sum = 0;
    int k;
    cin >> k;
    while(k--){
        cin >> now;
        sum += 5;
        if(now > pre){
            sum += 6*(now-pre);
            pre = now;
        }
        else{
            sum += 4*(pre-now);
            pre = now;
        }
    }
    cout << sum << endl;
    return 0;
}
