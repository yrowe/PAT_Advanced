#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 505;
int father[maxn];

void init(){
    for(int i = 0;i < maxn; ++i){
        father[i] = i;
    }
}

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}


int cnt[maxn] = {0};
bool root[maxn] = {false};
int main()
{
    freopen("input1126.txt", "r", stdin);
    init();
    int n, m;
    cin >> n >> m;
    while(m--){
        int v1, v2;
        cin >> v1 >> v2;
        Union(v1, v2);
        cnt[v1]++;
        cnt[v2]++;
    }
    int ans = 0;
    for(int i = 1;i <= n; ++i){
        root[findFather(i)] = true;
    }
    for(int i = 1;i <= n; ++i){
        ans += root[i];
    }

        int odd = 0;
        for(int i = 1; i <= n; ++i){
            if(i != n){
                cout << cnt[i] << " ";
            }
            else{
                cout << cnt[i] << endl;
            }
            if(cnt[i]%2 != 0)
                odd++;
        }
        if(ans > 1){
            cout << "Non-Eulerian" << endl;
            return 0;
        }
        if(odd == 0){
            cout << "Eulerian" << endl;
        }
        else if(odd == 2){
            cout << "Semi-Eulerian" << endl;
        }
        else{
            cout << "Non-Eulerian" << endl;
        }
    return 0;
}
