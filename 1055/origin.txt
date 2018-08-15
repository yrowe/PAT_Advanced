#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 100005;

struct person{
    char name[10];
    int age;
    int asset;
}all[maxn],valid[maxn];

bool cmp(person a,person b){
    if(a.asset != b.asset) return a.asset > b.asset;
    if(a.age != b.age) return a.age < b.age;
    return strcmp(a.name,b.name) < 0;
}

int cnt[maxn] = {0};

int main(){
    //freopen("inputa1055.txt","r",stdin);
    int n,q;
    int p = 0,valid_num = 0;
    scanf("%d %d",&n,&q);
    for(int i = 0;i < n;++i){
        scanf("%s %d %d",all[i].name,&all[i].age,&all[i].asset);
    }
    sort(all,all + n,cmp);

    for(int i = 0;i < n;++i){
        if(cnt[all[i].age] < 100){
            cnt[all[i].age]++;
            valid[valid_num++] = all[i];
        }
    }
//    for(int i = 0;i < valid_num;++i){
//        cout << valid[i].name << " " << valid[i].age << " " << valid[i].asset << endl;
//    }

    for(int i = 0;i < q;++i){
        int total,lowB,highB,pNum = 0;
        scanf("%d %d %d",&total,&lowB,&highB);
        printf("Case #%d:\n",i+1);
        for(int i = 0;i < valid_num;++i){
            if(valid[i].age >= lowB && valid[i].age <= highB){
                pNum++;
                printf("%s %d %d\n",valid[i].name,valid[i].age,valid[i].asset);
                if(pNum == total) break;
            }
        }

        if(pNum == 0)
            printf("None\n");
    }
}
