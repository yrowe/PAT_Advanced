#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

double change(string s){
    int flg = false;
    if(s[0] == '-'){
        flg = true;
        s.erase(0, 1);
    }
    double sum = 0;
    int index = s.find('.');
    if(index == -1){
        for(auto i:s){
            sum = sum*10 + i - '0';
        }
    }
    else{
        for(int i = 0; i < index; ++i){
            sum = sum*10 + s[i] - '0';
        }
        double x = 0.1;
        for(int i = index+1; i < s.size(); ++i){
            sum += (s[i]-'0')*x;
            x *= 0.1;
        }
    }
    if(flg == true){
        sum = -sum;
    }
    return sum;
}

bool judge(string s){
    for(auto i:s){
        if(i > '9' || i < '0'){
            if(i == '.' || i == '-')
                continue;
            return false;
        }
    }
    int cnt = count(s.begin(), s.end(), '.');
    if(cnt > 1){
        return false;
    }
    if(cnt == 1){
        if(s[0] == '-')
            s.erase(0, 1);
        int index = s.find('.');
        if(index + 2 < s.size()-1){
            return false;
        }
    }
    double num = change(s);
    if(num > 1000 || num < -1000)
        return false;
    return true;
}

int main()
{
    freopen("input1108.txt", "r", stdin);
    int n;
    cin >> n;
    vector<double> ans;
    while(n--){
        string tmp;
        cin >> tmp;
        if(judge(tmp) == false){
            cout << "ERROR: " << tmp << " is not a legal number" << endl;
        }
        else{
            ans.push_back(change(tmp));
        }
    }
    if(ans.size() == 0){
        cout << "The average of 0 numbers is Undefined" << endl;
        return 0;
    }
    else if(ans.size() == 1){
        printf("The average of 1 number is %.2f\n", ans[0]);
        return 0;
    }

    double aver = 0;
    for(auto i: ans){
        aver += i;
    }
    printf("The average of %d numbers is %.2f\n", ans.size(), aver/ans.size());
    return 0;
}
