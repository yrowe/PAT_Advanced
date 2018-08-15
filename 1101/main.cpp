#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int Max[maxn];
int Min[maxn];
int inp[maxn];

int main()
{
    freopen("input1101.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &inp[i]);
    }
    for(int i = 0; i < n; ++i){
        if(i == 0)
            Max[i] = inp[i];
        else{
            if(inp[i] > Max[i-1])
                Max[i] = inp[i];
            else
                Max[i] = Max[i-1];
        }
    }
    for(int i = n-1; i >= 0; --i){
        if(i == n-1)
            Min[i] = inp[i];
        else{
            if(inp[i] < Min[i+1])
                Min[i] = inp[i];
            else
                Min[i] = Min[i+1];
        }
    }
    vector<int> ans;
    for(int i = 0;i < n; ++i){
        if(i == 0){
            if(inp[i] < Min[i+1]){
                ans.push_back(inp[i]);
            }
        }
        else if(i == n-1){
            if(inp[i] > Max[i-1]){
                ans.push_back(inp[i]);
            }
        }
        else{
            if(inp[i] < Min[i+1] && inp[i] > Max[i-1]){
                ans.push_back(inp[i]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i > 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
