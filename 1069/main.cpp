#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

void reverse_s(int num, int &ans1, int &ans2){
    string s("");
    ans1 = 0;
    ans2 = 0;
    s += (num/1000 + '0');
    num %= 1000;
    s += (num/100 + '0');
    num %= 100;
    s += (num/10 + '0');
    s += (num%10 + '0');
    sort(s.rbegin(), s.rend());
    for(auto i:s){
        ans1 = ans1*10 + i - '0';
    }
    reverse(s.begin(), s.end());
    for(auto i: s){
        ans2 = ans2*10 + i - '0';
    }
}

bool judge(int n){
    int a,b,c,d;
    a = n/1000;
    n %= 1000;
    b = n/100;
    n %= 100;
    c = n/10;
    d = n%10;
    if(a == b&& b == c && c == d)
        return true;
    return false;
}

int main()
{
    freopen("input1069.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int a1 = 0, a2 = 0;
    do{
        reverse_s(n, a1, a2);
        printf("%04d - %04d = %04d\n", a1, a2, a1-a2);
        n = a1 - a2;
    }while(n != 6174 && n != 0);
    return 0;
}
