#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input1011.txt", "r", stdin);
    double w, t, l;
    double product = 1;
    for(int i = 0;i < 3;++i){
        cin >> w >> t >> l;
        if(w > l && w > t){
            product *= w;
            printf("W");
        }
        if(l > w && l > t){
            product *= l;
            printf("L");
        }
        if(t > w && t > l){
            product *= t;
            printf("T");
        }
        printf(" ");
    }

    printf("%.2f", (product*0.65-1)*2);
    return 0;
}
