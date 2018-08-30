#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int address, data, next;
}node[100005];

vector<Node> ans1, ans2, ans3, ans;

int main()
{
    freopen("input1133.txt", "r", stdin);
    int st, n, k;
    cin >> st >> n >> k;
    for(int i = 0;i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        node[a].address = a;
        node[a].data = b;
        node[a].next = c;
    }
    int p = st;
    while(p != -1){
        if(node[p].data < 0){
            ans1.push_back(node[p]);
        }
        else if(node[p].data > k){
            ans3.push_back(node[p]);
        }
        else{
            ans2.push_back(node[p]);
        }
        p = node[p].next;
    }

    for(auto i: ans1){
        ans.push_back(i);
    }
    for(auto i: ans2){
        ans.push_back(i);
    }
    for(auto i: ans3){
        ans.push_back(i);
    }

    for(int i = 0;i < ans.size(); ++i){
        if(i != ans.size()-1){
            //cout << ans[i].address << " " << ans[i].data << " " << ans[i+1].address << endl;
            printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i+1].address);
        }
        else{
            //cout << ans[i].address << " " << ans[i].data << " -1" << endl;
            printf("%05d %d -1\n", ans[i].address, ans[i].data);
        }
    }

    return 0;
}
