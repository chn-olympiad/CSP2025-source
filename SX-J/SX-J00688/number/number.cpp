#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t = 0, l;
	string s;
	cin >> s;
	l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++t] = (s[i] - '0');
		}
	}
	sort(a + 1, a + t + 1);
	if (a[t] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = t; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}