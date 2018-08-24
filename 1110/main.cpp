#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

const int maxn = 25;
struct Node{
    int lchild, rchild;
}node[maxn];

bool notRoot[maxn] = {false};

int main()
{
    freopen("input1110.txt", "r", stdin);
    int n;
    cin >> n;
    //scanf("%d\n", &n);
    for(int i = 0; i < n; ++i){
        //char lchild, rchild;
        //scanf("%c %c\n", &lchild, &rchild);
        string lchild, rchild;
        cin >> lchild >> rchild;
        if(lchild == "-"){
            node[i].lchild = -1;
        }
        else{
            stringstream ss(lchild);
			ss >> node[i].lchild;
            notRoot[node[i].lchild] = true;
        }
        if(rchild == "-"){
            node[i].rchild = -1;
        }
        else{
            stringstream ss(rchild);
            ss >> node[i].rchild;
            notRoot[node[i].rchild] = true;
        }
    }
    int root;
    for(root = 0; root < n; ++root){
        if(notRoot[root] == false)
            break;
    }
    int last;
    queue<int> q;
    int cnt = 0;
    cnt++;
    q.push(root);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(node[tmp].lchild != -1){
            q.push(node[tmp].lchild);
            cnt++;
        }
        else{
            last = q.back();
            break;
        }
        if(node[tmp].rchild != -1){
            q.push(node[tmp].rchild);
            cnt++;
        }
        else{
            last = q.back();
            break;
        }
    }
    if(cnt != n){
        cout << "NO " << root << endl;
    }
    else{
        cout << "YES " << last << endl;
    }
    return 0;
}
