#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string name;
    string id;
    int score;
    Student(string _name, string _id, int _score){
        name = _name;
        id = _id;
        score = _score;
    }
};

bool cmp(Student a, Student b){
    return a.score > b.score;
}

int main()
{
    freopen("input1083.txt", "r", stdin);
    vector<Student> inp;
    int n;
    int inp_min = 101;
    int inp_max = -1;
    cin >> n;
    string a, b;
    int c;
    while(n--){
        cin >> a >> b >> c;
        inp.push_back(Student(a,b,c));
        if(c < inp_min)
            inp_min = c;
        if(c > inp_max)
            inp_max = c;
    }
    int lower, upper;
    cin >> lower >> upper;
    if(inp_min > upper || inp_max < lower){
        cout << "NONE" << endl;
        return 0;
    }

    sort(inp.begin(), inp.end(), cmp);
    for(auto i:inp){
        if(i.score > upper)
            continue;
        if(i.score < lower)
            break;
        cout << i.name << " " << i.id << endl;
    }

    return 0;
}
