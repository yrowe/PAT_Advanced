#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

struct fraction{
    ll up;
    ll down;
};

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

void reduction(fraction &a){
    if(a.down < 0){
        a.down = -a.down;
        a.up = -a.up;
    }
    if(a.up == 0)
        a.down = 1;
    else{
        ll d = gcd(abs(a.up), abs(a.down));
        a.up /= d;
        a.down /= d;
    }

}

void print(fraction a){
    reduction(a);
    if(a.up == 0){
        printf("0");
    }
    else if(a.up < 0){
        if(a.up%a.down == 0){
            printf("(%lld)", a.up/a.down);
        }
        else{
            if(a.up/a.down == 0){
                printf("(%lld/%lld)", a.up, a.down);
            }
            else{
                printf("(%lld %lld/%lld)", a.up/a.down, -a.up%a.down, a.down);

            }
        }
    }
    else{
        if(a.up%a.down == 0){
            printf("%lld", a.up/a.down);
        }
        else{
            if(a.up/a.down == 0){
                printf("%lld/%lld", a.up, a.down);
            }
            else{
                printf("%lld %lld/%lld", a.up/a.down, a.up%a.down, a.down);

            }
        }
    }
}

fraction add(fraction a, fraction b){
    fraction c;
    c.up = a.up*b.down + a.down*b.up;
    c.down = a.down * b.down;
    return c;
}

fraction sub(fraction a, fraction b){
    fraction c;
    c.up = a.up*b.down - a.down*b.up;
    c.down = a.down * b.down;
    return c;
}

fraction mul(fraction a, fraction b){
    fraction c;
    c.up = a.up * b.up;
    c.down = a.down * b.down;
    return c;
}

fraction div(fraction a, fraction b){
    fraction c;
    c.up = a.up * b.down;
    c.down = a.down * b.up;
    return c;
}

int main()
{
    freopen("input1088.txt", "r", stdin);
    fraction f1, f2;
    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
    print(f1);
    printf(" + ");
    print(f2);
    printf(" = ");
    print(add(f1, f2));
    printf("\n");

    print(f1);
    printf(" - ");
    print(f2);
    printf(" = ");
    print(sub(f1, f2));
    printf("\n");

    print(f1);
    printf(" * ");
    print(f2);
    printf(" = ");
    print(mul(f1, f2));
    printf("\n");

    print(f1);
    printf(" / ");
    print(f2);
    printf(" = ");
    if(f2.up != 0)
        print(div(f1, f2));
    else
        printf("Inf");
    printf("\n");
    return 0;
}
