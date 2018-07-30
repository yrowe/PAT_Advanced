#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input1065.txt", "r", stdin);
    long long a, b, c;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a >> b >> c;
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0){
            cout << "Case #" << i << ": true" << endl;
        }
        else if(a < 0 && b < 0 && sum >= 0){
            cout << "Case #" << i << ": false" << endl;
        }
        else{
            if(sum > c)
                cout << "Case #" << i << ": true" << endl;
            else
                cout << "Case #" << i << ": false" << endl;
        }
    }
    return 0;
}
