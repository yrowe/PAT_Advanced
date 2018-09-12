#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1005;
int arr[maxn];
int m, n;
bool flg = true;

void judge(int i, int &tag){
    if(flg == false) return;
    if(i*2 <= n && i*2+1 <= n){
        if(arr[i] >= arr[i*2] && arr[i] >= arr[i*2+1]){
            if(tag == 0){
                flg = false;
            }
            tag = 1;
        }
        else if(arr[i] <= arr[i*2] && arr[i] <= arr[i*2+1]){
            if(tag == 1){
                flg = false;
            }
            tag = 0;
        }
        else{
            flg = false;
        }
        judge(i*2, tag);
        judge(i*2+1, tag);
    }
    else if(i*2 <= n){
        if(arr[i] >= arr[i*2]){
            if(tag == 0){
                flg = false;
            }
            tag = 1;
        }
        else{
            if(tag == 1){
                flg = false;
            }
            tag = 0;
        }
        judge(i*2, tag);
    }
    return;
}

int cnt;
void PostOrder(int p){
    if(p > n) return;
    PostOrder(p*2);
    PostOrder(p*2+1);
    cnt++;
    if(cnt != n){
        cout << arr[p] << " ";
    }
    else{
        cout << arr[p] << endl;
    }
}


int main()
{
    freopen("input1147.txt", "r", stdin);
    cin >> m >> n;
    while(m--){
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
        }
        int tag = -1;
        flg = true;
        judge(1, tag);
        if(flg == false){
            cout << "Not Heap" << endl;
        }
        else{
            if(tag == 1){
                cout << "Max Heap" << endl;
            }
            else{
                cout << "Min Heap" << endl;
            }
        }
        cnt = 0;
        PostOrder(1);

    }
    return 0;
}
