#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<char, int> key;

int main()
{
    freopen("input1112.txt", "r", stdin);
    int k;
    string s;
    cin >> k;
    cin >> s;
    s += "#";
    int rep = 1;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == s[i-1]){
            rep++;
        }
        else{
            if(rep%k == 0){
                // ¿ÉÄÜ»µµÄ
                if(key.find(s[i-1]) == key.end()){
                    key[s[i-1]] = 1;
                }
            }
            else{
                key[s[i-1]] = 0;
            }
            rep = 1;
        }
    }
    vector<char> broke;
    for(int i = 0; i < s.size()-1; ++i){
        char tmp = s[i];
        if(key[tmp] == 1){
            bool flg = true;
            for(int j = 0;j < broke.size(); ++j){
                if(broke[j] == tmp){
                    flg = false;
                    break;
                }

            }
            if(flg)
                broke.push_back(tmp);
        }
    }
    for(int i = 0;i < broke.size(); ++i){
        cout << broke[i];
    }
    cout << endl;
    for(int i = 0;i < s.size()-1; ++i){
        if(key[s[i]]){
            cout << s[i];
            i = i+k-1;
        }
        else{
            cout << s[i];
        }
    }
    return 0;
}
