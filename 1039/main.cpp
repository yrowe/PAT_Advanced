#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input1039.txt", "r", stdin);
    map<string, vector<int>> stu;
    int n, k;
    cin >> n >> k;
    while(k--){
        int tmp, ni;
        cin >> tmp >> ni;
        while(ni--){
            string s;
            cin >> s;
            stu[s].push_back(tmp);
        }
    }
    while(n--){
        string query;
        cin >> query;
        cout << query;
        cout << " " << stu[query].size();
        sort(stu[query].begin(), stu[query].end());
        for(auto i : stu[query]){
            cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}
