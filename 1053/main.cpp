#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 105;

struct Node{
    int value;
    vector<int> child;
}node[maxn];

vector<int> temp;
int target;

void DFS(int p, int Sum){
    Sum += node[p].value;
    if(Sum > target)
        return;
    if(Sum == target){
        if(node[p].child.size() != 0) return;
        temp.push_back(p);
        for(int i = 0;i < temp.size(); ++i){
            printf("%d", node[temp[i]].value);
            if(i != temp.size()-1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
        temp.pop_back();
        return;
    }
    temp.push_back(p);
    for(int i = 0;i < node[p].child.size(); ++i){
        DFS(node[p].child[i], Sum);
    }
    temp.pop_back();
}

bool cmp(int a, int b){
    return node[a].value > node[b].value;
}

int main()
{
    freopen("input1053.txt", "r", stdin);
    int n, m;
    scanf("%d %d %d", &n, &m, &target);
    for(int i = 0; i < n; ++i){
        scanf("%d", &node[i].value);
    }
    while(m--){
        int id, num;
        scanf("%d %d", &id, &num);
        while(num--){
            int tmp;
            scanf("%d", &tmp);
            node[id].child.push_back(tmp);
        }
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    DFS(0, 0);
    return 0;
}
