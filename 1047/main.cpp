#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int max1 = 40005;
const int max2 = 2505;

char name[max1][5];
vector<int> course[max2];

bool cmp(int a, int b){
    return strcmp(name[a], name[b]) < 0;
}

int main()
{
    freopen("input1047.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        char id[5];
        int num, index;
        scanf("%s %d", name[i], &num);
        while(num--){
            scanf("%d", &index);
            course[index].push_back(i);
        }
    }
    for(int i = 1; i <= k; ++i){
        printf("%d %d\n", i, course[i].size());
        int len = course[i].size();
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j = 0; j < course[i].size(); ++j){
            printf("%s\n", name[course[i][j]]);
        }
    }

    return 0;
}
