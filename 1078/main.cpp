#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 10010;
bool prime[maxn] = {false};
bool hashTable[maxn] = {false};

void prime_table(){
    prime[1] = true;
    for(int i = 2; i < maxn; ++i){
        if(prime[i] == false){
            for(int j = i+i;j < maxn; j += i){
                prime[j] = true;
            }
        }
    }
}


int main()
{
    freopen("input1078.txt", "r", stdin);
    prime_table();
    int msize, n;
    scanf("%d %d",&msize, &n);
    while(prime[msize] != false){
        msize++;
    }
    for(int i = 0;i < n; ++i){
        int tmp, M;
        scanf("%d", &tmp);
        M = tmp%msize;
        if(hashTable[M] == false){
            hashTable[M] = true;
            if(i > 0) printf(" ");
            printf("%d", M);
        }
        else{
            int probe;
            for(probe = 0; probe < msize; probe++){
                M = (tmp + probe*probe)%msize;
                if(hashTable[M] == false){
                    hashTable[M] = true;
                    if(i > 0) printf(" ");
                    printf("%d", M);
                    break;
                }
            }
            if(probe >= msize){
                if(i > 0) printf(" ");
                printf("-");
            }
        }
    }
    return 0;
}
