#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    freopen("input1051.txt", "r", stdin);
    int num, len, k;
    int arr[1010];
    cin >> num >> len >> k;
    while(k--){
        stack<int> st;
        bool flg = true;
        int current = 1;
        for(int i = 1;i <= len; ++i){
            cin >> arr[i];
        }
        for(int i = 1; i <= len; ++i){
            st.push(i);
            if(st.size() > num){
                flg = false;
                break;
            }
            while(st.size() > 0 && st.top() == arr[current]){
                st.pop();
                current++;
            }
        }
        if(st.empty() && flg) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
