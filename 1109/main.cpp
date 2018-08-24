#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct people{
    string name;
    int height;
    people(string _name, int _height){
        name = _name;
        height = _height;
    }
};

bool cmp(people a, people b){
    if(a.height != b.height)
        return a.height < b.height;
    return a.name > b.name;
}
vector<vector<string>> ans;
vector<people> stu;

void Photo(int st, int num){
    vector<string> cRow(num+1);
    vector<string> ordered;
    for(int i = st; i < st + num; ++i){
        ordered.push_back(stu[i].name);
    }
    int index = 0;
    cRow[num/2+1] = ordered[index++];
    for(int i = num/2; i >= 1; --i){
        cRow[i] = ordered[index];
        index += 2;
    }
    index = 2;
    for(int i = num/2+2; i <= num; ++i){
        cRow[i] = ordered[index];
        index = index + 2;
    }
    ans.push_back(cRow);
    return;
}


int main()
{
    freopen("input1109.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        string s1;
        int h1;
        cin >> s1 >> h1;
        stu.push_back(people(s1, h1));
    }
    sort(stu.rbegin(), stu.rend(), cmp);
    int rowNum = n/k;
    int row1 = rowNum + n%k;
    Photo(0, row1);
    for(int i = 1;i < k; ++i){
        Photo(row1 + (i-1)*rowNum, rowNum);
    }
    for(int i = 0;i < ans.size();++i){
        for(int j = 1;j < ans[i].size(); ++j){
            if(j != ans[i].size()-1){
                cout << ans[i][j] << " ";
            }
            else{
                cout << ans[i][j] << endl;
            }
        }
    }
    return 0;
}
