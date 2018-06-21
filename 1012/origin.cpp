#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

struct stu {
	string ID;
	int C, M, E, A;
	int r_C, r_M, r_E, r_A;
};

bool cmp_C(stu a, stu b) {
	return a.C > b.C;
}

bool cmp_M(stu a, stu b) {
	return a.M > b.M;
}

bool cmp_E(stu a, stu b) {
	return a.E > b.E;
}

bool cmp_A(stu a, stu b) {
	return a.A > b.A;
}

void best_rank(stu a) {
	if ((a.r_A <= a.r_C) && (a.r_A <= a.r_M) && (a.r_A <= a.r_E)) {
		cout << a.r_A << " " << "A" << endl;
	}
	else if ((a.r_C <= a.r_M) && (a.r_C <= a.r_E)) {
		cout << a.r_C << " " << "C" << endl;
	}
	else if (a.r_M <= a.r_E) {
		cout << a.r_M << " " << "M" << endl;
	}
	else {
		cout << a.r_E << " " << "E" << endl;
	}
	return;
}

int main() {
#ifdef _DEBUG
	ifstream cin("data.txt");
#endif
	vector<stu> students;
	vector<string> isHere;
	int n, m;
	cin >> n >> m;
	stu tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp.ID >> tmp.C >> tmp.M >> tmp.E;
		tmp.A = tmp.C + tmp.M + tmp.E;
		students.push_back(tmp);
		isHere.push_back(tmp.ID);
	}
	sort(students.begin(), students.end(), cmp_A);
	students[0].r_A = 1;
	for (int i = 1; i < students.size(); ++i) {
		if (students[i].A == students[i - 1].A) {
			students[i].r_A = students[i - 1].r_A;
		}
		else {
			students[i].r_A = i + 1;
		}
	}

	sort(students.begin(), students.end(), cmp_C);
	students[0].r_C = 1;
	for (int i = 1; i < students.size(); ++i) {
		if (students[i].C == students[i - 1].C) {
			students[i].r_C = students[i - 1].r_C;
		}
		else {
			students[i].r_C = i + 1;
		}
	}
	sort(students.begin(), students.end(), cmp_E);
	students[0].r_E = 1;
	for (int i = 1; i < students.size(); ++i) {
		if (students[i].E == students[i - 1].E) {
			students[i].r_E = students[i - 1].r_E;
		}
		else {
			students[i].r_E = i + 1;
		}
	}

	sort(students.begin(), students.end(), cmp_M);
	students[0].r_M = 1;
	for (int i = 1; i < students.size(); ++i) {
		if (students[i].M == students[i - 1].M) {
			students[i].r_M = students[i - 1].r_M;
		}
		else {
			students[i].r_M = i + 1;
		}
	}
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (find(isHere.begin(), isHere.end(), s) == isHere.end()) {
			cout << "N/A" << endl;
		}
		else {
			for (int j = 0; j < students.size(); ++j) {
				if (s == students[j].ID) {
					best_rank(students[j]);
					break;
				}
			}
		}
	}
	system("pause");
#ifdef _DEBUG
	cin.close();
#endif

	return 0;
}