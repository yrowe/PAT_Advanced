#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct sarray{
    string s1;
    string s2;
};

int main()
{
    freopen("input1035.txt", "r", stdin);
    int n;
    cin >> n;
    vector<sarray> ans;
    for(int i = 0; i < n; ++i){
        sarray tmp;
        cin >> tmp.s1 >> tmp.s2;
        bool flg = false;
        for(auto &i:tmp.s2){

            if(i == 'l'){
                flg = true;
                i = 'L';
            }
            if(i == '1'){
                flg = true;
                i = '@';
            }
            if(i == '0'){
                flg = true;
                i = '%';
            }
            if(i == 'O'){
                flg = true;
                i = 'o';
            }

        }
        if(flg){
            ans.push_back(tmp);
        }
    }
    int num = ans.size();
    if(num == 0){
        if(n == 1){
            cout << "There is 1 account and no account is modified" << endl;
        }
        else{
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
    }
    else{
        cout << num << endl;
        for(int i = 0; i < ans.size(); ++i){
            cout << ans[i].s1 << " " << ans[i].s2 << endl;
        }
    }
    return 0;
}
