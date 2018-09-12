#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

map<int, int> hashTable;
const int maxn = 100005;
struct node{
    int v, ad, next;
}Node[maxn];

int main()
{
    freopen("3.txt", "r", stdin);
    int n, st;
    cin >> n >> st;
    for(int i = 0;i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        Node[a].ad = a;
        Node[a].v = b;
        Node[a].next = c;
    }
    int p = st;
    vector<node> ans;
    while(p != -1){
        int id = abs(Node[p].v);
        if(hashTable[id] == 0){
            ans.push_back(Node[p]);
            hashTable[id] = 1;
        }
        p = Node[p].next;
    }
    //cout << ans.size() << " " << ans[0].ad << endl;
    if(ans.size() == 0){
        cout << "0 -1\n" << endl;
        return 0;
    }
    printf("%d %05d\n", ans.size(), st);
    for(int i = 0;i < ans.size(); ++i){
        printf("%05d %d", ans[i].ad, ans[i].v);
        if(i != ans.size()-1){
            //cout << ans[i].ad << " " << ans[i].v << " " << ans[i+1].ad << endl;
            printf(" %05d\n",ans[i+1].ad);
        }
        else{
            //cout << ans[i].ad << " " << ans[i].v << " -1" << endl;
            printf(" -1\n");
        }
    }

    return 0;
}
