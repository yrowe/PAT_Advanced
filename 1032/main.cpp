#include <iostream>
#include <cstdio>

using namespace std;

struct Node{
    int ad, next;
    char x;
}node[100005];

bool hashTable[100005] = {false};

int main()
{
    freopen("input1032.txt", "r", stdin);
    int st1, st2, num;
    scanf("%d %d %d", &st1, &st2, &num);
    while(num--){
        int ad, next;
        char x;
        scanf("%d %c %d", &ad, &x, &next);
        node[ad].ad = ad;
        node[ad].x = x;
        node[ad].next = next;
    }
    while(st1 != -1){
        hashTable[node[st1].ad] = true;
        st1 = node[st1].next;
    }
    //bool flg = false;
    while(st2 != -1){
        if(hashTable[node[st2].ad])
            break;
        st2 = node[st2].next;
    }
    if(st2 == -1){
        printf("-1\n");
    }
    else{
        printf("%05d\n", node[st2].ad);
    }
    return 0;
}
