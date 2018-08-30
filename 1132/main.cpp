#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int change(string s, int &a, int &b){
    int ans = 0;
    a = 0;
    b = 0;
    for(int i = 0;i < s.size()/2; ++i){
        a = a*10 + s[i] - '0';
        ans = ans*10 + s[i] - '0';
    }
    for(int i = s.size()/2; i < s.size(); ++i){
        b = b*10 + s[i] - '0';
        ans = ans*10 + s[i] - '0';
    }
    return ans;
}

int main()
{
    freopen("input1132.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--){
        string tmp;
        cin >> tmp;
        int a, b;
        int c = change(tmp, a, b);
        if(a == 0 || b == 0){
            cout << "No" << endl;
            continue;
        }
        if(c%a == 0 && (c/a)%b == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
