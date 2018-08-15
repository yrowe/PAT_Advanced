#include <iostream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("input1050.txt", "r", stdin);
    map<char, int> s;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(auto i: s2){
        s[i] = 1;
    }
    for(auto i: s1){
        if(s[i] == 0)
            cout << i;
    }
    return 0;
}
