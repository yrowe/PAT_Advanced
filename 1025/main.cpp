#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Stu{
    string id;
    int score;
    int room;
    int room_rank;
    int r;
};

vector<Stu> stu;

bool cmp(Stu a, Stu b){
    if(a.score != b.score){
        return a.score > b.score;
    }
    return a.id < b.id;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input1025.txt", "r", stdin);
    int n, room_num;
    int num = 0;
    cin >> n;
    for(int k = 1; k <= n; ++k){
        cin >> room_num;
        for(int i = 0;i < room_num; ++i){
            Stu tmp;
            cin >> tmp.id >> tmp.score;
            tmp.room = k;
            stu.push_back(tmp);
        }
        sort(stu.begin()+num, stu.begin()+num+room_num, cmp);
        int tmp_r = 1;
        for(int i = num; i < num+room_num; ++i){
            if(i == num){
                stu[i].room_rank = 1;
            }
            else{
                if(stu[i].score != stu[i-1].score){
                    tmp_r = i - num + 1;
                }
                stu[i].room_rank = tmp_r;
            }
        }
        num += room_num;
    }
    sort(stu.begin(), stu.begin()+num, cmp);
    int r = 1;
    for(int i = 0; i < num; ++i){
        if(i == 0){
            stu[i].r = 1;
        }
        else{
            if(stu[i].score != stu[i-1].score){
                r = i + 1;
            }
            stu[i].r = r;
        }
    }
    cout << num << endl;
    for(auto p:stu){
        cout << p.id << " " << p.r << " " << p.room << " " << p.room_rank << endl;
    }
    return 0;
}
