#include <bits/stdc++.h>
using namespace std;
int a[10000009];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int t = 0, h = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '1' && s[i] <= '9') {
			t++;
			a[t] = s[i] - '0';
		} else if (s[i] == '0')
			h++;
	}
	sort(a + 1, a + t + 1);
	for (int i = t; i >= 1; i--) {
		cout << a[i];
	}
	for (int i = 1; i <= h; i++) {
		cout << 0;
	}
	return 0;
}
