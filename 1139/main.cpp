#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10005;
bool isGirl[maxn];
vector<int> G[maxn];
bool vis[maxn];

struct node{
    int v1, v2;
    node(int _v1, int _v2){
        v1 = _v1;
        v2 = _v2;
    }
};
vector<node> ans;

int st, ed;
vector<int> tempPath;

void DFS(int s, int depth){
    if(depth > 3)
        return;
    vis[s] = true;
    if(s == ed){
        if(depth != 3){
            vis[s] = false;
            return;
        }

        tempPath.push_back(s);
        int a0 = tempPath[0];
        int a1 = tempPath[1];
        int a2 = tempPath[2];
        int a3 = tempPath[3];
        if(isGirl[a0] == isGirl[a1] && isGirl[a2] == isGirl[a3]){
            ans.push_back(node(tempPath[1], tempPath[2]));
        }
        tempPath.pop_back();
        vis[s] = false;
        return;
    }
    tempPath.push_back(s);
    for(int i = 0;i < G[s].size(); ++i){
        int v = G[s][i];
        if(vis[v] == false){

            DFS(v, depth+1);

        }
    }
    vis[s] = false;
    tempPath.pop_back();
}

bool cmp(node a, node b){
    if(a.v1 != b.v1)
        return a.v1 < b.v1;
    return a.v2 < b.v2;
}

int str2int(string s){
    int ans = 0;
    for(auto i: s){
        ans = ans*10 + i - '0';
    }
    return ans;
}

int main()
{
    freopen("input1139.txt", "r", stdin);
    fill(isGirl, isGirl+maxn, false);
    int n, m;
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    while(m--){
        string s1, s2;
        bool flg1 = false, flg2 = false;
        int v1, v2;
        cin >> s1 >> s2;
        if(s1[0] == '-'){
            flg1 = true;
            s1.erase(0, 1);
        }
        if(s2[0] == '-'){
            flg2 = true;
            s2.erase(0, 1);
        }
        v1 = str2int(s1);
        v2 = str2int(s2);
        if(flg1)
            isGirl[v1] = true;
        if(flg2)
            isGirl[v2] = true;

        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int q;
    //cin >> q;
    scanf("%d", &q);
    while(q--){
        //cin >> st >> ed;
        scanf("%d %d", &st, &ed);
        if(st < 0){
            st = -st;
        }
        if(ed < 0){
            ed = -ed;
        }
        fill(vis, vis+maxn, false);
        ans.clear();
        DFS(st, 0);
        sort(ans.begin(), ans.end(), cmp);
        //cout << ans.size() << endl;
        printf("%d\n", ans.size());
        for(auto i: ans){
            //cout << i.v1 << " " << i.v2 << endl;
            printf("%04d %04d\n", i.v1, i.v2);
        }
    }
    return 0;
}
