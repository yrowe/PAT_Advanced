#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
    int ad, x, next;
}Node[100005];

bool cmp(node a, node b){
    return a.x < b.x;
}

int main()
{
    freopen("input1052.txt", "r", stdin);
    int n, st;
    vector<node> v;
    scanf("%d %d", &n, &st);
    while(n--){
        node tmp;
        scanf("%d %d %d", &tmp.ad, &tmp.x, &tmp.next);
        Node[tmp.ad] = tmp;
    }
    while(st != -1){
        v.push_back(Node[st]);
        st = Node[st].next;
    }
    if(v.size() == 0){
        printf("0 -1\n");
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d %05d\n", v.size(), v[0].ad);
    for(int i = 0;i < v.size(); ++i){
        printf("%05d %d ", v[i].ad, v[i].x);
        if(i != v.size()-1){
            printf("%05d\n", v[i+1].ad);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
