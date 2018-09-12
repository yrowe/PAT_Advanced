#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 35;

struct node{
    string data;
    int lchild, rchild;
    node(){
        lchild = -1;
        rchild = -1;
    }
}N[maxn];

int n;
int notRoot[maxn] = {0};

double str2num(string s){
    stringstream ss;
    ss << s;
    double ans;
    ss >> ans;
    return ans;
}

double calculate(double a, double b, string c){
    if(c == "+") return a+b;
    if(c == "-") return a-b;
    if(c == "*") return a*b;
    if(c == "/") return a/b;
}

double inOrder(int v, int depth){
    if(N[v].lchild == -1 && N[v].rchild == -1){
        printf("%s", N[v].data.c_str());
        return str2num(N[v].data);
    }
    if(depth > 0) printf("(");
    double leftNum = inOrder(N[v].lchild, depth+1);

    printf("%s", N[v].data.c_str());
    double rightNum = inOrder(N[v].rchild, depth+1);
    if(depth > 0) printf(")");

    return calculate(leftNum, rightNum, N[v].data);
}

int main()
{
    freopen("p1005.txt", "r", stdin);
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> N[i].data;
    }
    for(int i = 0;i < n; ++i){
        string t1, t2;
        cin >> t1 >> t2;
        if(t1 != "-"){
            N[i].lchild = (int)str2num(t1);
            notRoot[N[i].lchild] = 1;
        }

        if(t2 != "-"){
            N[i].rchild = (int)str2num(t2);
            notRoot[N[i].rchild] = 1;
        }
    }
    int root;
    for(int i = 0;i < n; ++i){
        if(notRoot[i] == 0){
            root = i;
            break;
        }
    }
    double ans = inOrder(root, 0);
    printf(" %.2f", ans);

    return 0;
}
