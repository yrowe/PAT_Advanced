#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> string2int;
map<int, string> int2string;

const int maxn = 2010;
int G[maxn][maxn];
int visit[maxn] = {false};
int weight[maxn] = {0};

int n, thresh;
int index;

void DFS(int i, int &head, int &numMember, int &totalValue){
    numMember++;
    visit[i] = true;
    if(weight[i] > weight[head]){
        head = i;
    }
    for(int j = 1; j <= index; ++j){
        if(G[j][i] > 0){
            totalValue += G[j][i];
            G[j][i] = G[i][j] = 0;
            if(visit[j] == false){
                DFS(j, head, numMember, totalValue);
            }
        }
    }
}

map<string, int> gangster;

void DFSTrave(){
    for(int i = 1;i <= index; ++i){
        if(visit[i] == false){
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);

            if(numMember > 2 && totalValue > thresh){
                gangster[int2string[head]] = numMember;
            }
        }
    }
}

int main()
{
    freopen("input1034.txt", "r", stdin);
    fill(G[0], G[0]+maxn*maxn, 0);
    index = 1;
    //scanf("%d %d", &n, &thresh);
    cin >> n >> thresh;
    while(n--){
        string s1, s2;
        int value;
        cin >> s1 >> s2 >> value;
        if(string2int[s1] == 0){
            string2int[s1] = index;
            int2string[index] = s1;
            index++;
        }
        if(string2int[s2] == 0){
            string2int[s2] = index;
            int2string[index] = s2;
            index++;
        }
        int a1 = string2int[s1];
        int a2 = string2int[s2];
        G[a1][a2] += value;
        G[a2][a1] += value;
        weight[a1] += value;
        weight[a2] += value;
    }
    DFSTrave();
    cout << gangster.size() << endl;
    for(auto kk : gangster){
        cout << kk.first << " " << kk.second << endl;
    }
    return 0;
}
