#include <bits/stdc++.h>
using namespace std;
string a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	vector<int> v;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			int ai = a[i] - '0';
			v.push_back(ai);
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
	return 0;
}
