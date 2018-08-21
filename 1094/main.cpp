#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 105;

struct Node{
    vector<int> child;
    int level;
}node[maxn];

int cnt[maxn] = {0};

void BFS(){
    queue<int> q;
    q.push(1);
    node[1].level = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cnt[node[tmp].level]++;
        for(int i = 0;i < node[tmp].child.size(); ++i){
            int ch = node[tmp].child[i];
            node[ch].level = node[tmp].level + 1;
            q.push(ch);
        }
    }
}

int main()
{
    freopen("input1094.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--){
        int id, num;
        scanf("%d %d", &id, &num);
        while(num--){
            int tmp;
            scanf("%d", &tmp);
            node[id].child.push_back(tmp);
        }
    }
    BFS();
    int maxNum = -1;
    for(int i = 1; i < maxn; ++i){
        if(cnt[i] > cnt[maxNum])
            maxNum = i;
    }
    cout << cnt[maxNum] << " " << maxNum << endl;
    return 0;
}
