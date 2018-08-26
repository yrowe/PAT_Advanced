#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
map<int, int> couple;
int attend[maxn] = {false};
int main()
{
    freopen("input1121.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--){
        int id1, id2;
        cin >> id1 >> id2;
        couple[id1] = id2;
        couple[id2] = id1;
    }
    int k;
    cin >> k;
    vector<int> arr;
    vector<int> ans;
    while(k--){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        attend[tmp] = true;
    }
    for(auto i : arr){
        if(couple.find(i) != couple.end() && attend[couple[i]] == true){
            continue;
        }
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    //cout << ans.size() << endl;
    printf("%d\n", ans.size());
    for(int i = 0;i <ans.size(); ++i){
        if(i != ans.size()-1){
            //cout << ans[i] << " ";
            printf("%05d ", ans[i]);
        }
        else{
            //cout << ans[i] << endl;
            printf("%05d\n", ans[i]);
        }
    }
    return 0;
}
