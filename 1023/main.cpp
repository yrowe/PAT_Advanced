#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct bign{
    int a[25];
    int len;
};

bign change(string ss){
    bign b;
    b.len = ss.size();
    for(int i = 0;i < ss.size();++i){
        b.a[b.len-i-1] = ss[i]-'0';
    }

    return b;
}

bign mul2(bign b){
    int carry = 0;
    int i;
    for(i = 0;i < b.len; ++i){
        b.a[i] = b.a[i]*2 + carry;
        carry = b.a[i]/10;
        b.a[i] %= 10;
    }
    if(carry == 1){
        b.a[i] = 1;
        b.len++;
    }
    return b;
}

int num[10] = {0};

int main()
{
    string ss;
    cin >> ss;
    bign b = change(ss);
    for(int i = 0;i < b.len;++i){
        num[b.a[i]]++;
    }

    b = mul2(b);
    for(int i = 0;i < b.len; ++i){
        num[b.a[i]]--;
    }

    bool flg = true;  //不要忘记初始化！
    for(int i = 0;i < 10; ++i){
        if(num[i] != 0){
            flg = false;
            break;
        }
    }
    if(flg == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    for(int i = b.len-1; i >= 0; --i){
        cout << b.a[i];
    }
    return 0;
}
