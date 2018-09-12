#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, string> trans;

void init(){
    trans["zero"] = "0";
    trans["one"] = "1";
    trans["two"] = "2";
    trans["three"] = "3";
    trans["four"] = "4";
    trans["five"] = "5";
    trans["six"] = "6";
    trans["seven"] = "7";
    trans["eight"] = "8";
    trans["nine"] = "9";
}

int str2int(string a){
    int ans = 0;
    for(auto i: a){
        ans = ans*10 + i - '0';
    }
    return ans;
}

void judge(string a, string b, string c){
    vector<int> v;
    v.push_back(str2int(a));
    v.push_back(str2int(b));
    v.push_back(str2int(c));
    sort(v.rbegin(), v.rend());
    int aa = v[0], bb = v[1], cc = v[2];
    if(aa < bb+cc){
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }

}

int main()
{
    freopen("2.txt","r", stdin);
    init();
    int n;
    cin >> n;
    string s1(""), s2(""), s3("");
    while(n--){
        string tmp;
        cin >> tmp;
        s1 += trans[tmp];
    }
    cin >> n;
    while(n--){
        string tmp;
        cin >> tmp;
        s2 += trans[tmp];
    }
    cin >> n;
    while(n--){
        string tmp;
        cin >> tmp;
        s3 += trans[tmp];
    }
    judge(s1, s2, s3);

    return 0;
}
