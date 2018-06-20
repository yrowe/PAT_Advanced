#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10010;
int maxSum[maxn];
int start[maxn];
int inp[maxn];

int main()
{
    //test point 5 is wrong/
    freopen("input1007.txt", "r", stdin);
    int k;
    cin >> k;
    for(int i = 0;i < k;++i){
        cin >> inp[i];
    }
    maxSum[0] = inp[0];
    start[0] = 0;
    for(int i = 1; i < k;++i){
        if(maxSum[i-1] + inp[i] >= inp[i]){
            maxSum[i] = maxSum[i-1]+inp[i];
            start[i] = start[i-1];
        }
        else{
            maxSum[i] = inp[i];
            start[i] = i;
        }
    }
    int maxIndex = 0;
    int maxValue = maxSum[0];
    for(int i = 1;i < k;++i){
        if(maxSum[i] > maxValue){
            maxValue = maxSum[i];
            maxIndex = i;
        }
    }
    if(maxValue < 0){
        cout << "0 0 " << k-1 << endl;
    }
    else{
        cout << maxValue << " " << inp[start[maxIndex]] << " " << inp[maxIndex] << endl;
    }
    return 0;
}
