#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string convert(int a){
    string s = "00";
    if(a == 0)
        return s;
    int cnt = 1;
    while(a != 0){
        if(a%13 < 10)
            s[cnt--] = a%13 + '0';
        else
            s[cnt--] = a%13 - 10 + 'A';
        a /= 13;
    }
    return s;
}

int main(){
    //freopen("inputa1027.txt","r",stdin);
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    cout <<"#"<< convert(n1) << convert(n2) << convert(n3) << endl;
}
