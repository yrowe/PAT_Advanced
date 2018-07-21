#include <iostream>
#include <cstdio>
#include <vector>
#include<algorithm>
#include<set>

using namespace std;

const int maxn = 10010;
int father[maxn];
int visit[maxn] = {false};
vector<int> adj[maxn];
int maxDepth = -1;
int isRoot[maxn] = {0};

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

void DFS(int v, int depth, vector<int> &ans){
    visit[v] = true;
    if(depth == maxDepth){
        ans.push_back(v);

    }
    if(depth > maxDepth){
        maxDepth = depth;
        ans.clear();
        ans.push_back(v);
    }

    for(int i = 0;i < adj[v].size(); ++i){
        int u = adj[v][i];
        if(visit[u] == false){
            DFS(u, depth+1, ans);
        }
    }
}

int main()
{
    freopen("input1021.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        father[i] = i;
    }
    for(int i = 1;i <= n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        Union(u, v);
    }
    int block = 0;
    for(int i = 1;i <= n;++i){
        isRoot[findFather(i)]++;
    }
    for(int i = 1;i <= n;++i){
        if(isRoot[i] > 0) block++;
    }
    if(block > 1){
        cout << "Error: " << block << " components" << endl;
        return 0;
    }
    vector<int> ans1, ans2;
    set<int> out_ans;
    DFS(1, 0, ans1);
    fill(visit+1, visit+n+1, false);
    maxDepth = -1;
    DFS(ans1[0], 0, ans2);
    for(auto i:ans1)
        out_ans.insert(i);
    for(auto i:ans2)
        out_ans.insert(i);
    for(auto i:out_ans)
        cout << i << endl;

    return 0;
}
