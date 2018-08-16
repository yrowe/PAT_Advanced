#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100005;
bool prime[maxn] = {false};

void find_prime(){
    prime[1] = true;
    for(int i = 2; i < maxn; ++i){
        if(prime[i] == false){
            for(int j = i+i; j < maxn; j +=i){
                prime[j] = true;
            }
        }
    }
}

struct factor{
    int x;
    int cnt;
    factor(){
        cnt = 0;
    }
}factor[40];

int main()
{
    find_prime();
    int pNum = 0;
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1=1\n");
        return 0;
    }
    printf("%d=", n);
    int sqr = (int)sqrt(1.0*n);
    for(int i = 2; i <= sqr; ++i){
        if(prime[i] == true)
            continue;
        if(n%i == 0){
            factor[pNum].x = i;
            while(n%i == 0){
                factor[pNum].cnt++;
                n /= i;
            }
            pNum++;
        }
        if(n == 1) break;
    }
    if(n != 1){
        factor[pNum].x = n;
        factor[pNum].cnt++;
        pNum++;
    }


    for(int i = 0;i < pNum; ++i){
        if(i > 0) printf("*");
        printf("%d", factor[i].x);
        if(factor[i].cnt > 1){
            printf("^%d", factor[i].cnt);
        }
    }
    printf("\n");
    return 0;
}
