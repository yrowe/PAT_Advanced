#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("input1001.txt", "r", stdin);
    int a, b, sum;
    cin >> a >> b;
    sum = a + b;
    if(sum < 0){
        printf("-");
        sum = -sum;
    }
    if(sum < 1000){
        printf("%d", sum);
    }
    else if(sum < 1000000){
        printf("%d,%03d",sum/1000,sum%1000);
    }
    else{
        printf("%d,%03d,%03d",sum/1000000, (sum%1000000)/1000, sum%1000);
    }
    return 0;
}
