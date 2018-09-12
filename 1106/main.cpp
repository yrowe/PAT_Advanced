#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


const int maxn = 100005;
struct Node{
    vector<int> child;
    int level;
}node[maxn];

int minDepth = 100005;

void DFS(int p, int depth){
    if(node[p].child.size() == 0){
        node[p].level = depth;
        if(depth < minDepth){
            minDepth = depth;
        }
        return;
    }
    for(int i = 0;i < node[p].child.size(); ++i){
        DFS(node[p].child[i], depth+1);
    }
}

int main()
{
    freopen("input1106.txt", "r", stdin);
    int n;
    double P, r;
    vector<int> leaf;
    scanf("%d %lf %lf", &n, &P, &r);
    r = r/100;
    for(int i = 0;i < n; ++i){
        int num;
        scanf("%d", &num);
        if(num != 0){
            while(num--){
                int child;
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }
        else{
            leaf.push_back(i);
        }
    }
    DFS(0, 0);
    int cnt = 0;
    for(auto i: leaf){
        if(node[i].level == minDepth)
            cnt++;
    }
    printf("%.4f %d\n", pow(1+r, minDepth)*P, cnt);
    return 0;
}
