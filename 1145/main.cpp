#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100005;
int prime[maxn];
bool p[maxn] = {false};
int pNum = 0;
int arr[maxn] = {0};

void getPrime(){
    for(int i = 2; i < maxn; ++i){
        if(p[i] == false){
            prime[pNum++] = i;
            for(int j = i+i; j < maxn; j += i){
                p[j] = true;
            }
        }
    }
}

int main(){
    freopen("input1145.txt", "r", stdin);
    getPrime();
    int MSize, n, m;
    cin >> MSize >> n >> m;
    for(int i = 0;i < pNum; ++i){
        if(prime[i] >= MSize){
            MSize = prime[i];
            break;
        }
    }
    for(int i = 0;i < n; ++i){
        int tmp;
        cin >> tmp;
        int j;
        for(j = 0; j < MSize; ++j){
            int pos = (tmp+j*j)%MSize;
            if(arr[pos] == 0){
                arr[pos] = tmp;
                break;
            }
        }
        if(j == MSize){
            //cout << tmp << " cannot be inserted." << endl;
            printf("%d cannot be inserted.\n", tmp);
        }
    }
    int ans = 0;
    for(int i = 0;i < m; ++i){
        int tmp;
        cin >> tmp;
        for(int j = 0;j <= MSize; ++j){
            ans++;
            int pos = (tmp+j*j)%MSize;
            if(arr[pos] == tmp || arr[pos] == 0)
                break;
        }
    }
    printf("%.1f\n", ans*1.0/m);

}
