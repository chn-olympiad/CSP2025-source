#include <bits/stdc++.h>
using namespace std;

int a[1000005];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size(), p = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++p] = s[i] - '0';
		}
	}
	sort(a + 1, a + p + 1);
	for (int i = p; i >= 1; i--) {
		printf("%d", a[i]);
	}
	return 0;
}
