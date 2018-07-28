#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string Suit = "SHCD";
string num[] = {"1","2","3","4","5","6","7","8","9","10","11","12","13"};

int main()
{
    freopen("input1042.txt", "r", stdin);
    vector<string> v1, v2;
    v1.resize(55);
    v2.resize(55);
    int cnt = 1;
    for(int i = 0;i < 4; ++i){
        for(int j = 0;j < 13; ++j){
            v1[cnt] = Suit[i] + num[j];
            cnt++;
        }
    }
    v1[cnt++] = "J1";
    v1[cnt++] = "J2";
    v2 = v1;
    int n;
    int order[55];
    cin >> n;
    for(int i = 1;i <= 54; ++i){
        cin >> order[i];
    }
    while(n--){
        for(int i = 1;i <= 54; ++i){
            v2[order[i]] = v1[i];
        }
        v1 = v2;
    }
    cout << v1[1];
    for(int i = 2; i <= 54; ++i){
        cout << " " << v1[i];
    }

}
