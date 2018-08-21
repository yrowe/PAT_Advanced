#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

const int maxn = 100005;
struct Node{
    vector<int> child;
    int amount;
    int level;
}node[maxn];

void BFS(){
    queue<int> q;
    q.push(0);
    node[0].level = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < node[tmp].child.size(); ++i){
            int c = node[tmp].child[i];
            node[c].level = node[tmp].level + 1;
            q.push(c);
        }
    }
}

int main()
{
    freopen("input1079.txt", "r", stdin);
    int n;
    double P, r;
    scanf("%d %lf %lf", &n, &P, &r);
    vector<int> root;
    for(int i = 0; i < n; ++i){
        int num;
        scanf("%d", &num);
        if(num != 0){
            while(num--){
                int tmp;
                scanf("%d", &tmp);
                node[i].child.push_back(tmp);
            }
        }
        else{
            scanf("%d", &node[i].amount);
            root.push_back(i);
        }
    }

    BFS();

    double sum = 0;
    for(auto i: root){
        sum += node[i].amount * pow((100+r)/100, node[i].level);
    }
    sum *= P;
    printf("%.1f\n", sum);
    return 0;
}
