#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int hobby[maxn] = {0};
int father[maxn];

void init(){
    for(int i = 1;i < maxn; ++i)
        father[i] = i;
}

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(father[a] != a){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

int cnt[maxn] = {0};
bool cmp(int a, int b){
    return a > b;
}

int main()
{
    freopen("input1107.txt", "r", stdin);
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int num;
        scanf("%d:", &num);
        while(num--){
            int id;
            scanf("%d", &id);
            if(hobby[id] == 0){
                hobby[id] = i;
            }
            int h = hobby[id];
            Union(i, h);
        }
    }
    map<int, int> ans;
    for(int i = 1; i <= n; ++i){
        ans[findFather(i)]++;
        cnt[findFather(i)]++;
    }
    sort(cnt, cnt+n+1, cmp);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i != ans.size()-1) cout << cnt[i] << " ";
        else cout << cnt[i] << endl;
    }
    return 0;
}
