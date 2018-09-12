#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n, tmp;
    while(scanf("%d", &n) != EOF){
        priority_queue<int, vector<int>, greater<int>> q;
        while(n--){
            scanf("%d", &tmp);
            q.push(tmp);
        }
        int ans = 0;
        while(q.size() != 1){
            int v1 = q.top();
            q.pop();
            int v2 = q.top();
            q.pop();
            q.push(v1+v2);
            ans += v1 + v2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
