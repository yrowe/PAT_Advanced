#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

struct stu{
    int id, score[6], total, num;
    bool flg;
    stu(){
        for(int i = 0;i < 6; ++i)
            score[i] = -2;
        total = 0;
        num = 0;
        flg = false;
    }
}s[10005];

bool cmp(stu a, stu b){
    if(a.total != b.total)
        return a.total > b.total;
    if(a.num != b.num)
        return a.num > b.num;
    return a.id < b.id;
}

int main()
{
    freopen("input1075.txt", "r", stdin);

    int n, k, m;
    int full_score[6];
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= k; ++i){
        scanf("%d", &full_score[i]);
    }
    while(m--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(s[a].score[b] < c)
            s[a].score[b] = c;
        if(c != -1)
            s[a].flg = true;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(s[i].score[j] == full_score[j])
                s[i].num++;
            if(s[i].score[j] >= 0)
                s[i].total += s[i].score[j];
        }
    }
    for(int i = 1; i <= n; ++i){
        s[i].id = i;
    }
    sort(s+1, s+n+1, cmp);

    int r = 1;
    for(int i = 1;i <= n; ++i){
        if(s[i].flg == false)
            break;
        if(i == 1)
            printf("1 ");
        else{
            if(s[i].total != s[i-1].total)
                r = i;
            printf("%d ", r);
        }
        printf("%05d %d", s[i].id, s[i].total);
        for(int j = 1;j <= k; ++j){
            if(s[i].score[j] == -2)
                printf(" -");
            else if(s[i].score[j] == -1)
                printf(" 0");
            else{
                printf(" %d", s[i].score[j]);
            }
        }
        printf("\n");

    }
    return 0;
}
