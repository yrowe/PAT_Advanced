#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int order[10005];
int main()
{
    freopen("input1041.txt", "r", stdin);
    int n;
    cin >> n;
    map<int, int> num;

    int index = 0;
    while(n--){
        int tmp;
        cin >> tmp;
        if(num[tmp] == 0){
            num[tmp] = 1;
            order[index++] = tmp;
        }

        else
            num[tmp]++;
    }
    for(int i = 0;i < index; ++i){
        if(num[order[i]] == 1){
            cout << order[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;

    return 0;
}
