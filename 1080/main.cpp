#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    int G, GE, id, wish[5], r;
};

bool cmp(Student a, Student b){
    if(a.G != b.G)
        return a.G > b.G;
    return a.GE > b.GE;
}

int main()
{
    freopen("input1080.txt", "r", stdin);
    vector<Student> v;
    int quota[105]={0};
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> school[m];
    for(int i = 0;i < m; ++i){
        scanf("%d", &quota[i]);
    }
    for(int i = 0; i < n; ++i){
        Student tmp;
        scanf("%d %d", &tmp.GE, &tmp.G);
        tmp.G += tmp.GE;
        for(int j = 0;j < k; ++j){
            scanf("%d", &tmp.wish[j]);
        }
        tmp.id = i;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);
    int r = 0;
    for(int i = 0;i < n; ++i){
        if(i > 0 && v[i].G == v[i-1].G && v[i].GE == v[i-1].GE)
            v[i].r = v[i-1].r;
        else
            v[i].r = i;
    }
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < k; ++j){
            int target = v[i].wish[j];
            if(quota[target] == 0)
                continue;
            else if(school[target].size() < quota[target]){
                school[target].push_back(v[i].id);
                break;
            }
            else{
                int index = school[target][school[target].size()-1];
                if(v[i].r == v[index].r){
                    school[target].push_back(v[i].id);
                    break;
                }
            }
        }
    }
    for(int i = 0;i < m; ++i){
        if(school[i].empty())
            cout << endl;
        else{
            sort(school[i].begin(), school[i].end());
            cout << school[i][0];
            for(int j = 1;j < school[i].size(); ++j){
                cout << " " << school[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
