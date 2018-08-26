#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10005;
int father[maxn];
bool isRoot[maxn] = {false};
void init(){
    for(int i = 0; i < maxn; ++i){
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

int main()
{
    freopen("input1118.txt", "r", stdin);
    init();
    int maxIndex = -1;
    int n;
    scanf("%d", &n);
    while(n--){
        int k, Index;
        scanf("%d", &k);
        int fir;
        scanf("%d", &fir);
        if(fir > maxIndex){
            maxIndex = fir;
        }
        k--;
        while(k--){
            scanf("%d", &Index);
            if(Index > maxIndex){
                maxIndex = Index;
            }
            Union(fir, Index);
        }
    }

    for(int i = 1; i <= maxIndex; ++i){
        isRoot[findFather(i)] = true;
    }
    int ans = 0;
    for(int i = 1; i <= maxIndex; ++i){
        if(isRoot[i])
            ans++;
    }
    cout << ans << " " << maxIndex << endl;
    int m;
    scanf("%d", &m);
    while(m--){
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        if(findFather(id1) == findFather(id2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
