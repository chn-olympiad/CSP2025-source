#include <bits/stdc++.h>
using namespace std;
string  a[10];

bool cmp(string a, string b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int  m = 0;
	string s;
	cin >> s;
	int l = s.size();
	for (int i = 0; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++m] = s[i];
		}
	}
	sort(a + 1, a + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		cout << a[i];
	}

	return 0;
}
