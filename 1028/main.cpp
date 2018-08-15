#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int t;   //类型，作为cmp判断依据

struct stu{
    char id[10];
    char name[10];
    int score;
};


bool cmp(stu a,stu b){
    int s = strcmp(a.id,b.id);
    int n = strcmp(a.name,b.name);
    if(t == 1)
        return s < 0;
    if(t == 2){
        if(n != 0) return n < 0;
        else return s < 0;
    }
    if(t == 3){
        if(a.score != b.score) return a.score < b.score;
        else return s < 0;
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //freopen("inputa1028.txt","r",stdin);
    int n;
    vector<stu> S;
    //cin >> n >> t;
    scanf("%d %d\n",&n,&t);
    for(int i = 0;i < n;++i){
        stu tmp;
        //cin >> tmp.id >> tmp.name >> tmp.score;
        scanf("%s %s %d",tmp.id,tmp.name,&tmp.score);
        S.push_back(tmp);
    }

    sort(S.begin(),S.end(),cmp);

    for(auto it:S){
        //cout << it.id << " " << it.name << " " << it.score << endl;
        printf("%s %s %d\n",it.id,it.name,it.score);
    }

}
