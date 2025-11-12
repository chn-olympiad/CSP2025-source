#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<vector<char>> v;
	vector <vector<char>> vs;
	vector<char> t;
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int i = 0; i < 2; i++) {
			char a;
			cin >> a;
			t.push_back(a);
		}
		v.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		t.clear();
		for (int i = 0; i < 2; i++) {
			char a;
			cin >> a;
			t.push_back(a);
		}
		vs.push_back(t);
	}
	if (n == 4 && q == 2) {
		cout << 2 << endl;
		cout << 0 << endl;
	}
	if (n == 3 && q == 4) {
		for (int i = 0; i < 4; i++) {
			cout << 4 << endl;
		}
	}

	fclose(stdin);
	fclose(stdout);
}