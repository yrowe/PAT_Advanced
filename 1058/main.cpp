#include <iostream>
#include <cstdio>

using namespace std;

struct money{
    int Galleon, Sickle, Knut;
    money(int _Galleon, int _Sickle, int _Knut){
        Galleon = _Galleon;
        Sickle = _Sickle;
        Knut = _Knut;
    }

};

int main()
{
    freopen("input1058.txt","r", stdin);
    int a,b,c;
    scanf("%d.%d.%d", &a, &b, &c);
    money A(a,b,c);
    scanf("%d.%d.%d", &a, &b, &c);
    money B = money(a,b,c);
    money C = money(A.Galleon+B.Galleon, A.Sickle+B.Sickle, A.Knut+B.Knut);
    if(C.Knut >= 29){
        C.Knut -= 29;
        C.Sickle++;
    }
    if(C.Sickle >= 17){
        C.Sickle -= 17;
        C.Galleon++;
    }
    printf("%d.%d.%d\n",C.Galleon,C.Sickle,C.Knut);
    return 0;
}
