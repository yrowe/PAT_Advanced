#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int maxn = 25;
bool notRoot[maxn] = {false};

struct node{
    string s;
    int lchild, rchild;
}node[maxn];

int k;
void inOrder(int p, string &s){
    if(node[p].rchild == -1 && node[p].lchild == -1){
        s = node[p].s;
        return;
    }
    string s1(""), s2(node[p].s), s3("");
    if(node[p].lchild != -1){
        inOrder(node[p].lchild, s1);
    }
    if(node[p].rchild != -1){
        inOrder(node[p].rchild, s3);
    }
    if(p == k){
        s = s1 + s2 + s3;

    }
    else{
        s = "(" + s1 + s2 + s3 + ")";
    }

}

int main()
{
    freopen("input1130.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1;i <= n; ++i){
        string tmps;
        int l, r;
        cin >> tmps >> l >> r;
        if(l != -1){
            notRoot[l] = true;
        }
        if(r != -1){
            notRoot[r] = true;
        }
        node[i].s = tmps;

        node[i].lchild = l;
        node[i].rchild = r;
    }

    for(k = 1; k <= n; ++k){
        if(notRoot[k] == false)
            break;
    }
    string s("");
    inOrder(k, s);
    cout << s << endl;
    return 0;
}
