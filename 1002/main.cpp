#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1001;
double coef[maxn] = {0};

int main()
{
    freopen("input1002.txt", "r", stdin);
    int k, e;
    double c;
    for(int i = 0;i < 2; ++i){
        scanf("%d",&k);
        while(k--){
            scanf("%d %lf",&e, &c);
            coef[e] += c;
        }
    }

    int cnt = 0;
    for(int i = maxn-1; i >= 0; --i){
        if (coef[i] != 0){
            cnt++;
        }
    }

    if(cnt == 0){
        printf("0");
        return 0;
    }

    printf("%d", cnt);
    for (int i = maxn-1; i>= 0; --i){
        if(coef[i] != 0){
            printf(" %d %.1f", i, coef[i]);
        }
    }
    return 0;
}
