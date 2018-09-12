#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string int2str(int b){
    string s2("");
    while(b != 0){
        s2 += ((b%10)+'0');
        b /= 10;
    }
    reverse(s2.begin(), s2.end());
    return s2;
}

int main()
{
    freopen("input1140.txt", "r", stdin);
    int d, n;
    cin >> d >> n;
    string s("");
    s += (d + '0');
    string tmp("");
    int num = 1;
    while(--n){
        for(int i = 0;i < s.size(); ++i){
            if(i == 0){
                tmp += s[0];
                num = 1;
            }
            else if(s[i] != s[i-1]){
                tmp += int2str(num);
                tmp += s[i];
                num = 1;
            }
            else{
                num++;
            }
        }
        if(num != 0){
            tmp += int2str(num);

        }
        s = tmp;
        tmp.clear();
        num = 0;
    }
    cout << s << endl;
    return 0;
}
