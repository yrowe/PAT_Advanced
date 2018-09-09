#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

string unit[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string ten[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string earth2mar[170];
map<string, int> mar2earth;

void init(){
    for(int i = 0;i < 13; ++i){
        earth2mar[i] = unit[i];
        mar2earth[unit[i]] = i;
    }
    for(int i = 0;i < 13;++i){
        earth2mar[13*i] = ten[i];
        mar2earth[ten[i]] = i*13;
    }
    for(int i = 1;i < 13;++i){
        for(int j = 1;j < 13; ++j){
            string str = ten[i] + " " + unit[j];
            earth2mar[13*i+j] = str;
            mar2earth[str] = 13*i+j;
        }
    }
}

int main()
{
    freopen("input1100.txt", "r", stdin);
    init();
    int T;
    cin >> T;
    cin.ignore();
    string s;
    while(T--){
        getline(cin, s);
        if(s[0] >= '0' && s[0] <= '9'){
            int num = 0;
            for(auto x: s)
                num = num*10 + x - '0';
            cout << earth2mar[num] << endl;
        }
        else{
            cout << mar2earth[s] << endl;
        }
    }
    return 0;
}
