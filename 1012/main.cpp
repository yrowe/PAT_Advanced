#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct stu{
    string id;
    int C, M, E, A;
    int rC, rM, rE, rA;
};

bool cmp_C(stu a, stu b){
    if (a.C > b.C){
        return true;
    }
    return false;
}

bool cmp_M(stu a, stu b){
    if (a.M > b.M){
        return true;
    }
    return false;
}

bool cmp_E(stu a, stu b){
    if (a.E > b.E){
        return true;
    }
    return false;
}

bool cmp_A(stu a, stu b){
    if (a.A > b.A){
        return true;
    }
    return false;
}

int main()
{
    freopen("input1012.txt", "r", stdin);
    vector<stu> all;
    int n, m;
    cin >> n >> m;
    while(n--){
        stu tmp;
        cin >> tmp.id >> tmp.C >> tmp.M >> tmp.E;
        tmp.A = tmp.C + tmp.M + tmp.E; //用和代替均值。
        all.push_back(tmp);
    }

    sort(all.begin(), all.end(), cmp_C);
    all[0].rC = 1;
    for(int i = 1; i < all.size(); ++i){
        if(all[i].C == all[i-1].C){
            all[i].rC = all[i-1].rC;
        }
        else{
            all[i].rC = i + 1;
        }
    }

    sort(all.begin(), all.end(), cmp_E);
    all[0].rE = 1;
    for(int i = 1; i < all.size(); ++i){
        if(all[i].E == all[i-1].E){
            all[i].rE = all[i-1].rE;
        }
        else{
            all[i].rE = i + 1;
        }
    }

    sort(all.begin(), all.end(), cmp_M);
    all[0].rM = 1;
    for(int i = 1;i < all.size(); ++i){
        if(all[i].M == all[i-1].M){
            all[i].rM = all[i-1].rM;
        }
        else{
            all[i].rM = i + 1;
        }
    }

    sort(all.begin(), all.end(), cmp_A);
    all[0].rA = 1;
    for(int i = 1; i < all.size(); ++i){
        if(all[i].A == all[i-1].A){
            all[i].rA = all[i-1].rA;
        }
        else{
            all[i].rA = i + 1;
        }
    }

    while(m--){
        string target;
        cin >> target;
        int k = -1;
        for(int i = 0; i < all.size(); ++i){
            if(all[i].id == target){
                k = i;
                break;
            }
        }
        if(k == -1){
            cout << "N/A" << endl;
            continue;
        }
        if(all[k].rA <= all[k].rC && all[k].rA <= all[k].rM && all[k].rA <= all[k].rE){
            cout << all[k].rA << " A" << endl;
        }
        else if(all[k].rC <= all[k].rA && all[k].rC <= all[k].rM && all[k].rC <= all[k].rE){
            cout << all[k].rC << " C" << endl;
        }
        else if(all[k].rM <= all[k].rC && all[k].rM <= all[k].rA && all[k].rM <= all[k].rE){
            cout << all[k].rM << " M" << endl;
        }
        else{
            cout << all[k].rE << " E" << endl;
        }
    }

    return 0;
}
