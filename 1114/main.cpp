#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10005;
int father[maxn];
int isRoot[maxn] = {0};

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
        if(faA < faB){
            father[faB] = faA;
        }
        else{
            father[faA] = faB;
        }
    }
}

struct node{
    int estate, area;
    node(int _estate, int _area){
        estate = _estate;
        area = _area;
    }
    node(){
    }
};

struct fam{
    int id;
    int num;
    double te;
    double ta;
};
vector<fam> vv;

bool cmp(fam a, fam b){
    if(a.ta != b.ta)
        return a.ta > b.ta;
    return a.id < b.id;
}

map<int, node> prop;
int main()
{
    freopen("input1114.txt", "r", stdin);

    set<int> ss;
    init();
    int n;
    scanf("%d", &n);
    while(n--){
        int id, fa, ma;
        scanf("%d %d %d", &id, &fa, &ma);
        ss.insert(id);
        if(fa != -1){
            Union(id, fa);
            ss.insert(fa);
        }
        if(ma != -1){
            Union(id, ma);
            ss.insert(ma);
        }
        int k, child;
        scanf("%d", &k);
        while(k--){
            scanf("%d", &child);
            Union(id, child);
            ss.insert(child);
        }
        int e, a;
        scanf("%d %d", &e, &a);
        prop[id] = node(e, a);
    }
    for(auto i: ss){
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    vector<int> outp;
    for(auto i: ss){
        if(isRoot[i] > 0){
            ans++;
            outp.push_back(i);
        }
    }
    printf("%d\n", ans);
    for(auto j: outp){
        int total_estate = 0, total_area = 0;

        for(auto i: ss){
            if(findFather(i) == j && prop.find(i) != prop.end()){
                total_estate += prop[i].estate;
                total_area += prop[i].area;
            }
        }
        fam tmp;
        tmp.id = j;
        tmp.num = isRoot[j];
        tmp.te = total_estate*1.0/isRoot[j];
        tmp.ta = total_area*1.0/isRoot[j];
        vv.push_back(tmp);
    }
    sort(vv.begin(), vv.end(), cmp);
    for(auto j: vv){
        printf("%04d %d %.3f %.3f\n", j.id, j.num, j.te, j.ta);
    }

    return 0;
}
