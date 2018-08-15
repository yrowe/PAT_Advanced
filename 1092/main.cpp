#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    freopen("input1092.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> num;
    for(auto i:s2){
        if(num[i] == 0){
            num[i] = 1;
        }
        else{
            num[i]++;
        }
    }
    for(auto i:s1){
        if(num.find(i) == num.end())
            continue;
        num[i]--;
    }

    int D = 0;
    for(auto i:num){
        //cout << i.first << " " << i.second << endl;
        if(i.second > 0){
            D += i.second;
        }
    }
    if(D == 0){
        cout << "Yes " << s1.size() - s2.size() << endl;
    }
    else{
        cout << "No " << D << endl;
    }

    return 0;
}
