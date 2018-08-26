#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

const int maxn = 10005;
bool appear[maxn] = {false};
bool prime[maxn];

void getPrime(){
    for(int i = 2; i < maxn; ++i){
        prime[i] = true;
    }
    for(int i = 2; i < maxn; ++i){
        if(prime[i] == true){
            for(int j = i+i; j < maxn; j += i){
                prime[j] = false;
            }
        }
    }
}

int main()
{
    freopen("input1116.txt","r", stdin);
    getPrime();
    map<int, int> R;
    int n;
    int id;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> id;
        R[id] = i;
    }
    int k, q;
    cin >> k;
    while(k--){
        cin >> q;
        if(R[q] == 0){
            printf("%04d: Are you kidding?\n", q);
            continue;
        }
        else{
            if(appear[q] == true){
                printf("%04d: Checked\n", q);
                continue;
            }
            int ra = R[q];
            appear[q] = true;
            if(ra == 1){
                printf("%04d: Mystery Award\n", q);
                continue;
            }
            if(prime[ra] == true){
                printf("%04d: Minion\n", q);
            }
            else{
                printf("%04d: Chocolate\n", q);
            }
        }
    }
    return 0;
}
