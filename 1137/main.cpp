#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 10005;

struct stu{
    int G, Gf, Gm, Gp, pscore;
    string id;
    stu(){
        Gf = -1;
        Gm = -1;
        G = -1;
        Gp = -1;
    }
}Stu[maxn];

bool cmp(stu a, stu b){
    if(a.Gp != b.Gp)
        return a.Gp > b.Gp;
    if(a.G != b.G){
        return a.G > b.G;
    }
    return a.id < b.id;
}

int main()
{
    freopen("input1137.txt", "r", stdin);
    int p, m, n;
    map<string, int> id2index;
    //scanf("%d %d %d", &p, &m, &n);
    cin >> p >> m >> n;
    int index = 1;
    while(p--){
        string tmp;
        int gp;
        cin >> tmp >> gp;
        if(id2index[tmp] == 0){
            Stu[index].id = tmp;
            if(gp >= 200){
                Stu[index].Gp = 1;
            }
            Stu[index].pscore = gp;
            id2index[tmp] = index++;
        }
        else{
            int id = id2index[tmp];
            Stu[id].id = tmp;
            if(gp >= 200){
                Stu[id].Gp = 1;
            }
            Stu[id].pscore = gp;
        }
    }
    while(m--){
        string tmp;
        int gm;
        cin >> tmp >> gm;
        if(id2index[tmp] != 0){
            int id = id2index[tmp];
            Stu[id].Gm = gm;
        }
    }
    while(n--){
        string tmp;
        int gf;
        cin >> tmp >> gf;
        int id = id2index[tmp];
        if(id2index[tmp] != 0){
            Stu[id].Gf = gf;
        }
    }
    for(int i = 1;i <= index; ++i){

        if(Stu[i].Gf != -1 && Stu[i].Gm != -1){
            if(Stu[i].Gf < Stu[i].Gm){
                Stu[i].G = round(Stu[i].Gm*0.4 + Stu[i].Gf*0.6);
            }
            else{
                Stu[i].G = Stu[i].Gf;
            }

        }
        else if(Stu[i].Gf != -1){
            Stu[i].G = Stu[i].Gf;
        }
    }
    sort(Stu + 1, Stu+index+1, cmp);
    for(int i = 1;i <= index; ++i){
        if(Stu[i].G < 60)
            break;

        cout << Stu[i].id << " " << Stu[i].pscore << " " << Stu[i].Gm << " " << Stu[i].Gf << " " << Stu[i].G << endl;
    }
    return 0;
}
