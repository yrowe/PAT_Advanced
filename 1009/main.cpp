#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 2005;
double ans[maxn] = {0};

struct poly{
    int exp;
    double coef;
};

int main()
{
    freopen("input1009.txt", "r", stdin);
    vector<poly> p1, p2;
    int k;
    cin >> k;
    while(k--){
        poly tmp;
        cin >> tmp.exp >> tmp.coef;
        p1.push_back(tmp);
    }
    cin >> k;
    while(k--){
        poly tmp;
        cin >> tmp.exp >> tmp.coef;
        p2.push_back(tmp);
    }

    for(int i = 0;i < p1.size(); ++i){
        for(int j = 0;j < p2.size(); ++j){
            int e = p1[i].exp + p2[j].exp;
            double c = p1[i].coef * p2[j].coef;
            ans[e] += c;
        }
    }

    int notZero = 0;
    for(int i = 0;i < maxn;++i){
        if(ans[i] != 0){
            notZero++;
        }
    }
    printf("%d", notZero);
    for(int i = maxn-1; i >= 0; --i){
        if(ans[i] != 0){
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}
