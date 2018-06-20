#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
int aa[] = {1,2,3};

int main()
{
    freopen("input1005.txt", "r", stdin);
    string china[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string inp;
    int sum = 0;
    cin >> inp;
    for(int i = 0; i < inp.size(); ++i){
        sum += inp[i] - '0';
    }
    // max sum < 1000
    if (sum < 10){
        cout << china[sum] << endl;
    }
    else if (sum < 100){
        cout << china[sum/10] << " " << china[sum%10] << endl;
    }
    else{
        cout << china[sum/100] << " " << china[(sum%100)/10] << " " << china[(sum%100)%10] << endl;
    }

    return 0;
}
