#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct node{
    vector<int> child;
    int level;
};

const int maxn = 110;
bool notRoot[maxn] = {false};
node aa[maxn];
int levelNum[maxn];

int main()
{
    //freopen("input1004.txt", "r", stdin);
    int n, m, k, id, num, ch;
    cin >> n >> m;
    while(m--){
        cin >> id >> num;
        while(num--){
            cin >> ch;
            aa[id].child.push_back(ch);
            notRoot[ch] = true;
        }
    }

    //index start from 1;
    int r;
    for(int i = 1;i <= n; ++i){
        if(notRoot[i] == false){
            r = i;
            break;
        }
    }

    queue<int> q;

    aa[r].level = 0;
    q.push(r);
    int tmpNode, childNode;
    int maxLevel = 0;
    while(!q.empty()){
        tmpNode = q.front();
        if (aa[tmpNode].level > maxLevel){
            maxLevel = aa[tmpNode].level;
        }
        if (aa[tmpNode].child.size() == 0){
            levelNum[aa[tmpNode].level]++;
        }
        q.pop();
        for(int i = 0; i < aa[tmpNode].child.size(); ++i){
            childNode = aa[tmpNode].child[i];
            aa[childNode].level = aa[tmpNode].level + 1;
            q.push(childNode);
        }
    }

    for(int i = 0;i <= maxLevel; ++i){
        if (i != maxLevel){
            printf("%d ", levelNum[i]);
        }
        else{
            printf("%d", levelNum[i]);
        }
    }

    return 0;
}
