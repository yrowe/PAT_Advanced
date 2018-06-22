#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 100010;
bool Prime[maxn] = {false};

bool isPrime(int N) {
	for (int i = 2; i*i <= N; ++i) {
		if (N%i == 0) {
			return false;
		}
	}
	return true;
}

int Xreverse(int x, int r){
    vector<int> num;
    int sum = 0;
    while(x != 0){
        num.push_back(x%r);
        x /= r;
    }
    int exp = 0;
    for(vector<int>::reverse_iterator p = num.rbegin(); p != num.rend(); ++p){
        sum += *p * int(pow(r, exp));
        exp++;
    }
    return sum;
}

int main()
{
    freopen("input1015.txt", "r", stdin);
    for(int i = 2;i < maxn; ++i){
        Prime[i] = isPrime(i);
    }
    int n, d;
    while(true){
        cin >> n;
        if(n < 0)
            break;
        cin >> d;
        int rn = Xreverse(n, d);
        if(Prime[n] && Prime[rn]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
