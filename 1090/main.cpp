#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100005;

struct Node{
    vector<int> child;
    int level;
}node[maxn];

int root;
int cnt[maxn] = {0};
int maxDepth = 0;

void BFS(){
    queue<int> q;
    q.push(root);
    node[root].level = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(node[tmp].level > maxDepth){
            maxDepth = node[tmp].level;
        }
        cnt[node[tmp].level]++;
        for(int i = 0; i < node[tmp].child.size(); ++i){
            int ch = node[tmp].child[i];
            node[ch].level = node[tmp].level + 1;
            q.push(ch);
        }

    }
}

int main()
{
    freopen("input1090.txt", "r", stdin);
    int num;
    double P, r;
    scanf("%d %lf %lf", &num, &P, &r);
    r = r/100;
    for(int i = 0; i < num; ++i){
        int father;
        scanf("%d", &father);
        if(father != -1){
            node[father].child.push_back(i);
        }
        else{
            root = i;
        }
    }

    BFS();

    printf("%.2f %d", pow(1+r, maxDepth)*P, cnt[maxDepth]);
    return 0;
}
