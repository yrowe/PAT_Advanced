#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 15;
bool notRoot[maxn] = {false};

struct node{
    int lchild, rchild;
}Node[maxn];

int n;

void print_level_order(int st){
    queue<int> q;
    q.push(st);
    int cnt = 0;
    while(!q.empty()){
        int tmp;
        tmp = q.front();
        q.pop();
        if(cnt != n-1){
            printf("%d ", tmp);
        }
        else{
            printf("%d\n", tmp);
        }
        cnt++;
        if(Node[tmp].rchild != -1)
            q.push(Node[tmp].rchild);
        if(Node[tmp].lchild != -1)
            q.push(Node[tmp].lchild);
    }
}

int in_cnt = 0;

void in_order(int st){
    if(Node[st].rchild != -1)
        in_order(Node[st].rchild);
    if(in_cnt != n-1){
        printf("%d ", st);
    }
    else{
        printf("%d\n",st);
    }
    in_cnt++;
    if(Node[st].lchild != -1)
        in_order(Node[st].lchild);
}

int main()
{
    freopen("input1102.txt", "r", stdin);
    scanf("%d\n", &n);
    for(int i = 0; i < n; ++i){
        char c1, c2;
        scanf("%c %c\n",&c1,&c2);
        if(c1 == '-'){
            Node[i].lchild = -1;
        }
        else{
            Node[i].lchild = c1 - '0';
            notRoot[c1-'0'] = true;
        }
        if(c2 == '-'){
            Node[i].rchild = -1;
        }
        else{
            Node[i].rchild = c2 - '0';
            notRoot[c2-'0'] = true;
        }
    }
    int k;
    for(k = 0; k < n; ++k){
        if(notRoot[k] == false)
            break;
    }

    print_level_order(k);
    in_order(k);
    return 0;
}
