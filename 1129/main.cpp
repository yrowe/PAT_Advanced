#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    friend bool operator < (node a, node b){
        if(a.cnt != b.cnt)
            return a.cnt > b.cnt;
        else
            return a.value < b.value;
    }
};
int main() {
    freopen("input1129.txt", "r", stdin);
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);
        book[num]++;
        s.insert(node{num, book[num]});
    }
    return 0;
}
