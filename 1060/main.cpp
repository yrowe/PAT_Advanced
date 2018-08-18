#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int n;

string deal(string s, int &e){
    int k = 0;
    while(s.size() > 0 && s[0]== '0'){
        s.erase(s.begin());
    }
    if(s[0]=='.'){
        s.erase(s.begin());
        while(s.size() > 0 && s[0]== '0'){
            s.erase(s.begin());
            e--;
        }
    }
    else{
        while(k < s.size() && s[k] != '.'){
            k++;
            e++;
        }
        if(k < s.size()){
            s.erase(s.begin()+k);
        }
    }

    if(s.size() == 0){
        e = 0;
    }
    int num = 0;
    k = 0;
    string res;
    while(num < n){
        if(k < s.size()) res += s[k++];
        else res += '0';
        num++;
    }
    return res;
}

int main()
{
    freopen("input1060.txt", "r", stdin);
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s1 = deal(s1, e1);
    s2 = deal(s2, e2);
    if(s1 == s2 && e1 == e2){
        cout << "YES 0." << s1 << "*10^" << e1 << endl;
    }
    else{
        cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl;
    }
    return 0;
}
