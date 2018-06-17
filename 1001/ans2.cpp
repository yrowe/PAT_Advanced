#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main() {
#本题更广的解法，更多位也能适应
#ifdef _DEBUG
	ifstream cin("data.txt");
#endif

	int a, b, sum, num;
	bool sgn;
	string s, outp;
	cin >> a >> b;
	sum = a + b;

	if (sum == 0) {
		cout << "0" << endl;
		return 0;
	}
	if (sum > 0)
		sgn = true;
	else {
		sgn = false;
		sum = -sum;
	}

	while (sum != 0) {
		num = sum % 10;
		sum /= 10;
		s += num + '0';
	}

	int cnt = 0;

	for (int i = 0; i < s.size(); ++i) {
		outp += s[i];
		cnt++;
		if ((cnt % 3 == 0) && (i != s.size()-1))
			outp += ',';
	}

	if (!sgn)
		outp += '-';

	for (auto p = outp.rbegin(); p != outp.rend(); ++p) {
		cout << *p;
	}



#ifdef _DEBUG
	cin.close();
#endif

	return 0;
}
