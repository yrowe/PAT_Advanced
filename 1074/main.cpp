#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Node{
    int x;
    int ad, next;
}node[100005];

stack<int> s;

int main()
{
    freopen("input1074.txt", "r", stdin);
    int st, n, k;
    scanf("%d %d %d", &st, &n, &k);
    for(int i = 0;i < n; ++i){
        int a1, x, a2;
        scanf("%d %d %d", &a1, &x, &a2);
        node[a1].x = x;
        node[a1].ad = a1;
        node[a1].next = a2;
    }
    int num = 0;
    int tmp = st;
    while(num < k){
        s.push(tmp);
        tmp = node[tmp].next;
        num++;
    }


    st = s.top();
    while(!s.empty()){
        int index = s.top();
        s.pop();
        int next_index;
        if(!s.empty()){
            next_index = s.top();
        }else{
            next_index = tmp;
        }
        node[index].next = next_index;
    }

    while(st != -1){
        if(node[st].next != -1){
            printf("%05d %d %05d\n", st, node[st].x, node[st].next);
        }
        else{
            printf("%05d %d -1\n", st, node[st].x);
        }

        st = node[st].next;
    }
    return 0;
}
