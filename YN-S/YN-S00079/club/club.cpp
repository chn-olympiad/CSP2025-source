#include <bits/stdc++.h>
using namespace std;

class Student {
	public:
		int a1, a2, a3;
		Student(int a1, int a2, int a3) {
			this->a1 = a1;
			this->a2 = a2;
			this->a3 = a3;
		}
};

int process(vector<Student> v, int pos, int one, int two, int three, int people) {


	if (one > people) {
		return -v[pos].a1;
	}
	if (two > people) {
		return -v[pos].a2;
	}
	if (three > people) {
		return -v[pos].a3;
	}
	if (pos > v.size() || pos == v.size()) {
		return 0;
	}



	int n1 = v[pos].a1 + process(v, pos + 1, one + 1, two, three, people);
	int n2 = v[pos].a2 + process(v, pos + 1, one, two + 1, three, people);
	int n3 = v[pos].a3 + process(v, pos + 1, one, two, three + 1, people);
	return max(n1, max(n2, n3));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		vector<Student> v;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			v.push_back(Student(a1, a2, a3));
		}
//		for (int j = 0; j < v.size(); j++) {
//			cout << v[j].a1 << " " << v[j].a2 << " " << v[j].a3 << " " << endl;
//		}
//		cout << "----------------------------------------------------------" << endl;
		cout << process(v, 0, 0, 0, 0, n / 2) << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
//I don't know why??????????
//who knows????????
//nobody can do it,I even can not work the beyonding problem
//bomb shit