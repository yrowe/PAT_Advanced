#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct fraction{
    int up, down;
    fraction(int _up, int _down){
        up = _up;
        down = _down;
    }
    fraction(){}
};

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

fraction reduction(fraction a){
    if(a.down < 0){
        a.down = -a.down;
        a.up = -a.up;
    }
    if(a.up == 0)
        a.down = 1;
    else{
        int d = gcd(a.up, a.down);
        a.up /= d;
        a.down /= d;
    }
    return a;
}

void add(fraction &a, fraction b){
    int u, d;
    u = a.up*b.down + b.up*a.down;
    d = a.down * b.down;
    a.up = u;
    a.down = d;
    a = reduction(a);
}

int main()
{
    freopen("input1081.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    fraction ans(0, 1);
    fraction tmp;
    while(n--){
        scanf("%d/%d", &tmp.up, &tmp.down);
        add(ans, tmp);
    }
    if(ans.up % ans.down == 0){
        printf("%d\n", ans.up/ans.down);
    }
    else{
        if(ans.up / ans.down == 0){
            printf("%d/%d\n", ans.up, ans.down);
        }
        else{
            if(ans.up > 0)
                printf("%d %d/%d\n", ans.up/ans.down, ans.up%ans.down, ans.down);
            else{
                //doesn't affect answer, but this code should be added.
                printf("%d %d/%d\n", ans.up/ans.down, -ans.up%ans.down, ans.down);
            }
        }
    }

    return 0;
}
