#include <bits/stdc++.h>
using namespace std;
int a[1000005], n, c = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, t = "";
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c++;
			a[i + 1] = s[i] - '0';
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i > n - c; i--) {
		cout << a[i];
	}
	return 0;
}
