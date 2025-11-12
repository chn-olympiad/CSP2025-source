#include <bits/stdc++.h>
using namespace std;

bool cmp(short x, short y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	short a[1000005];
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		cout << a[i];
	}
	return 0;
}
