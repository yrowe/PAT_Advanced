#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input1125.txt", "r", stdin);
    priority_queue<double, vector<double>, greater<double>> q;
    int n;
    cin >> n;
    while(n--){
        double tmp;
        cin >> tmp;
        q.push(tmp);
    }
    while(q.size() != 1){
        double t1 = q.top();
        q.pop();
        double t2 = q.top();
        q.pop();
        t1 = (t1+t2)/2;
        q.push(t1);
    }
    cout << floor(q.top()) << endl;
    return 0;
}
