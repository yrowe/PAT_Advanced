#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node{
    int ad, x, next;
}Node[100005];

bool hashTable[10005] = {false};

int main()
{
    freopen("input1097.txt", "r", stdin);
    int st, n;
    scanf("%d %d", &st, &n);
    while(n--){
        node tmp;
        scanf("%d %d %d", &tmp.ad, &tmp.x, &tmp.next);
        Node[tmp.ad] = tmp;
    }
    vector<node> v1, v2;
    while(st != -1){
        if(hashTable[abs(Node[st].x)] == false){
            hashTable[abs(Node[st].x)] = true;
            v1.push_back(Node[st]);
        }
        else{
            v2.push_back(Node[st]);
        }
        st = Node[st].next;
    }
    for(int i = 0;i < v1.size(); ++i){
        printf("%05d %d ", v1[i].ad, v1[i].x);
        if(i != v1.size()-1){
            printf("%05d\n", v1[i+1]);
        }
        else{
            printf("-1\n");
        }
    }

    for(int i = 0;i < v2.size(); ++i){
        printf("%05d %d ", v2[i].ad, v2[i].x);
        if(i != v2.size()-1){
            printf("%05d\n", v2[i+1]);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
