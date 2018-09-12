#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct people{
    int virtue, talent, total;
    char id[10];
    int kind;
};

vector<people> p;

bool cmp(people a, people b){
    if(a.kind != b.kind)
        return a.kind < b.kind;
    if(a.total != b.total)
        return a.total > b.total;
    if(a.virtue != b.virtue)
        return a.virtue > b.virtue;
    return strcmp(a.id, b.id) < 0;
    //return a.id < b.id;
}

int main()
{
    //ios::sync_with_stdio(false);
    freopen("input1062.txt", "r", stdin);
    int n, low, high;
    //cin >> n >> low >> high;
    scanf("%d %d %d",&n, &low, &high);
    for(int i = 0;i < n; ++i){
        people tmp;
        scanf("%s%d%d",tmp.id,&tmp.virtue,&tmp.talent);
        //cin >> tmp.id >> tmp.virtue >> tmp.talent;
        if(tmp.virtue < low || tmp.talent < low){
            continue;
        }
        tmp.total = tmp.virtue + tmp.talent;
        if(tmp.virtue >= high && tmp.talent >= high){
            tmp.kind = 1;

        }
        else if(tmp.virtue >= high){
            tmp.kind = 2;
        }
        else if(tmp.virtue >= tmp.talent){
            tmp.kind = 3;
        }
        else{
            tmp.kind = 4;
        }
        p.push_back(tmp);
    }
    sort(p.begin(), p.end(), cmp);

    //cout << p.size() << endl;
    printf("%d\n",p.size());
    for(auto i:p){
        //cout << i.id << " " << i.virtue << " " << i.talent << endl;
        printf("%s %d %d\n",i.id, i.virtue, i.talent);
    }

    return 0;
}
