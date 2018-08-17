#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

const int maxn = 55;
set<int> s[maxn];

double iou(int x, int y){
    int total_num = s[x].size(), same_num = 0;
    for(auto i: s[y]){
        if(s[x].find(i) != s[x].end()) same_num++;
        else total_num++;
    }
    return same_num*100.0/total_num;
}

int main()
{
    freopen("input1063.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        int num;
        scanf("%d", &num);
        while(num--){
            int tmp;
            scanf("%d", &tmp);
            s[i].insert(tmp);
        }
    }
    int k;
    scanf("%d", &k);
    while(k--){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%.1f%\n", iou(x, y));
    }
    return 0;
}
