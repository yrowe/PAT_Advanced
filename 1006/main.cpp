#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int str2time(string s){
    int hh = (s[0]-'0')*10 + s[1]-'0';
    int mm = (s[3]-'0')*10 + s[4]-'0';
    int ss = (s[6]-'0')*10 + s[7]-'0';
    return hh*60*60 + mm*60 + ss;
}


int main()
{
    //freopen("input1006.txt", "r", stdin);
    int k;
    string id;
    int earliestTime, lastTime;
    earliestTime = str2time("24:00:00");
    lastTime = 0;
    string earliest, last, s1, s2;
    int time1, time2;
    cin >> k;
    while(k--){
        cin >> id >> s1 >> s2;
        time1 = str2time(s1);
        time2 = str2time(s2);
        if(time1 < earliestTime){
            earliestTime = time1;
            earliest = id;
        }
        if(time2 > lastTime){
            lastTime = time2;
            last = id;
        }
    }
    cout << earliest << " " << last << endl;

    return 0;
}
