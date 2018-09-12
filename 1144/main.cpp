#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10000005;

map<int, int> hashTable;

int main()
{
    freopen("input1144.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--){
        int tmp;
        scanf("%d", &tmp);
        if(tmp > 0){
            hashTable[tmp] = 1;
        }
    }
    for(int i = 1;i < maxn; ++i){
        //数可能会很多，但是答案并不很大。maxn取100005足以
        if(hashTable[i] == 0){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
