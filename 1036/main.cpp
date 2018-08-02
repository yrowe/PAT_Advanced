#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct gender{
    string name;
    string id;
};

bool flg_male = false;
bool flg_female = false;

int main()
{
    freopen("input1036.txt", "r", stdin);
    int n;
    int highest = -1;
    int lowest = 101;
    gender male, female;
    cin >> n;
    while(n--){
        gender tmp;
        string tag;
        int score;
        cin >> tmp.name >> tag >> tmp.id >> score;
        if(tag == "M"){
            flg_male = true;
            if(score < lowest){
                lowest = score;
                male = tmp;
            }
        }
        else{
            flg_female = true;
            if(score > highest){
                highest = score;
                female = tmp;
            }
        }
    }
    if(flg_female){
        cout << female.name << " " << female.id << endl;
    }
    else{
        cout << "Absent" << endl;
    }
    if(flg_male){
        cout << male.name << " " << male.id << endl;
    }
    else{
        cout << "Absent" << endl;
    }
    if(flg_female && flg_male){
        cout << highest - lowest << endl;
    }
    else{
        cout << "NA" << endl;
    }
    return 0;
}
