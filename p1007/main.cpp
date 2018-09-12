#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

struct stu{
    int a, b, c, d, l;
    string id;
    stu(){
    }
    stu(string _id, int _a, int _b, int _c, int _d){
        id = _id;
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        l = a + b + c + d;
    }
};

bool cmp(stu a, stu b){
    if(a.l != b.l)
        return a.l > b.l;
    return a.id < b.id;
}

vector<stu> ans;

int main()
{
    freopen("7.txt", "r", stdin);
    int a, b, c, d, l;
    int n;
    cin >> a >> b >> c >> d >> l;
    cin >> n;
    while(n--){
        int tmpa, tmpb, tmpc, tmpd;
        int total = 0;
        string tmpid;
        cin >> tmpid >> tmpa >> tmpb >> tmpc >> tmpd;
        total = tmpa + tmpb + tmpc + tmpd;
        if(tmpa >= a && tmpb >= b && tmpc >= c && tmpd >=d &&total >= l){
            ans.push_back(stu(tmpid, tmpa, tmpb, tmpc, tmpd));
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for(auto i: ans){
        cout << i.id << " " << i.l << endl;
    }
    return 0;
}
