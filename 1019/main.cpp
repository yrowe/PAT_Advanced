#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> num;

int main()
{
    freopen("input1019.txt", "r", stdin);
    int n, b;
    cin >> n >> b;
    if(n == 0){
        cout << "Yes" << endl;
        cout << 0 << endl;
        return 0;
    }
    while(n != 0){
        num.push_back(n%b);
        n /= b;
    }

    int len = num.size();
    bool flg = false;
    for(int i = 0; i < len/2; ++i){
        if(num[i] != num[len-i-1]){
            flg = true;
            cout << "No" << endl;
            break;
        }
    }
    if(!flg)
        cout << "Yes" << endl;
    for(int i = num.size()-1; i >= 0; --i){
        if(i != 0){
            cout << num[i] << " ";
        }
        else{
            cout << num[i] << endl;
        }
    }
    return 0;
}
