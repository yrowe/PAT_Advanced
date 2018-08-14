#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    freopen("input1082.txt", "r", stdin);
    vector<string> inp;
    int n;
    cin >> n;
    getchar();
    string tmp;
    int minLen = 300;
    for(int i = 0;i < n; ++i){
        getline(cin, tmp);
        reverse(tmp.begin(), tmp.end());
        inp.push_back(tmp);
        if(tmp.size() < minLen)
            minLen = tmp.size();
    }
    int ans = 0;
    for(int i = 0;i < minLen; ++i){
        bool flg = false;
        char c = inp[0][i];
        for(int j = 1; j < inp.size(); ++j){
            if(c != inp[j][i]){
                flg = true;
                break;
            }
        }
        if(flg == true)
            break;
        ans++;
    }
    if(ans == 0){
        cout << "nai" << endl;
    }
    else{
        for(int i = ans-1; i >= 0; --i){
            cout << inp[0][i];
        }
        cout << endl;
    }
    return 0;
}
