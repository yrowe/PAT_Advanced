#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 100005;
struct school{
    double tws;
    int ns;
    int total;
    string name;
    school(){
        tws = 0;
        ns = 0;
    }
}sc[maxn];

void lower(string &s){
    for(auto &i: s){
        i = tolower(i);
//        if(i >= 'A' && i <= 'Z'){
//            i = i - ('A' - 'a');
//        }
    }
    cout << s << endl;
}

bool cmp(school a, school b){
    if(a.total != b.total)
        return a.total > b.total;
    if(a.ns != b.ns)
        return a.ns < b.ns;
    return a.name < b.name;
}

int main()
{
    freopen("input1141.txt", "r", stdin);
    int index = 1;
    map<string, int> dic;
    int n;
    cin >> n;
    while(n--){
        string s1, s2;
        int score;
        cin >> s1 >> score >> s2;
        lower(s2);
        if(dic[s2] == 0){
            dic[s2] = index;
            sc[index].name = s2;
            index++;
        }
        int id = dic[s2];
        sc[id].ns++;
        if(s1[0] == 'B'){
            sc[id].tws += (score/1.5);
        }
        else if(s1[0] == 'A'){
            sc[id].tws += score;
        }
        else{
            sc[id].tws += (score*1.5);
        }
    }
    for(int i = 1; i < index; ++i){
        sc[i].total = (int)sc[i].tws;
    }
    sort(sc+1, sc+index, cmp);
    cout << index-1 << endl;
    int r = 1;
    for(int i = 1;i < index; ++i){
        if(i == 1){
            cout << r << " " << sc[i].name << " " << sc[i].total << " " << sc[i].ns << endl;
        }
        else{
            if(sc[i].total != sc[i-1].total){
                r = i;
            }
            cout << r << " " << sc[i].name << " " << sc[i].total << " " << sc[i].ns << endl;
        }
    }
    return 0;
}
