#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input1093.txt", "r", stdin);
    long long T=0, AT=0, PAT=0;
    string s;
    cin >> s;
    for(auto i = s.rbegin(); i != s.rend(); ++i){
        if(*i == 'T') T++;
        if(*i == 'A') AT += T;
        if(*i == 'P') PAT += AT;
    }
    cout << PAT%1000000007 << endl;
    return 0;
}
