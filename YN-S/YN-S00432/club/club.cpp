#include <bits/stdc++.h>
using namespace std;

class Student {
	public:
		int a1;
		int a2;
		int a3;
		Student(int a1, int a2, int a3) {
			this->a1 = a1;
			this->a2 = a2;
			this->a3 = a3;
		}
};

long long process(vector<Student> &vs, int pos, int v1, int v2, int v3, long long num) {
	if (v1 > (vs.size() / 2) || v2 > (vs.size() / 2) || v3 > (vs.size() / 2)) {
//		cout << "v1:" << v1.size() << "v2:" << v2.size() << "v3:" << v3.size() << endl;
//		if (v1.size() > (vs.size() / 2)) {
//			v1.pop_back();
//		}
//		if (v2.size() > (vs.size() / 2)) {
//			v2.pop_back();
//		}
//		if (v3.size() > (vs.size() / 2)) {
//			v3.pop_back();
//		}
		return 0;
	}
	if (pos >= vs.size()) {
		return num;
	}
	int n1 = 0;
//	if (v1 < (vs.size() / 2)) {
	n1 = process(vs, pos + 1, v1 + 1, v2, v3, num + vs[pos].a1);
//		v1--;
//	}
	int n2 = 0;
//	if (v2 < (vs.size() / 2)) {
	n2 = process(vs, pos + 1, v1, v2 + 1, v3, num + vs[pos].a2);
//		v2--;
//	}
	int n3 = 0;
//	if (v3 < (vs.size() / 2)) {
	n3 = process(vs, pos + 1, v1, v2, v3 + 1, num + vs[pos].a3);
//		v3--;
//	}
	return max(n1, max(n2, n3));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
	int v1, v2, v3 = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<Student> vs;
		int n1;
		cin >> n1;
		for (int j = 0; j < n1; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			Student s = Student(a, b, c);
			vs.push_back(s);
		}
//		for (int k = 0; k < vs.size(); k++) {
//			cout << vs[k].a1 << " " << vs[k].a2 << " " << vs[k].a3 << endl;
//		}
		long long ans = process(vs, 0, v1, v2, v3, 0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

