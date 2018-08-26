#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

int cnt(string s){
    int a = 0;
    for(auto i: s){
        a += i - '0';
    }
    return a;
}

int main()
{
    freopen("input1120.txt", "r", stdin);
    int n;
    cin >> n;
    set<int> ans;
    while(n--){
        string s;
        cin >> s;
        ans.insert(cnt(s));
    }
    cout << ans.size() << endl;
    int num = 0;
    for(auto i: ans){
        if(num != ans.size()-1){
            cout << i << " ";
        }
        else{
            cout << i << endl;
        }
        num++;
    }
    return 0;
}
