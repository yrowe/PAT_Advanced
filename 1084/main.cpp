#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    freopen("input1084.txt", "r", stdin);
    map<char, int> key;
    string s1, s2;
    set<char> se;
    cin >> s1 >> s2;
    for(auto &i: s1){
        i = toupper(i);
    }
    for(auto &i: s2){
        i = toupper(i);
        se.insert(i);
    }
    for(auto i: s1){
        if(key[i] == 0 && se.find(i) == se.end()){
            key[i] = 1;
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
