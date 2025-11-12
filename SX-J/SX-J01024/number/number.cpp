#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.length(), vis = 0;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++vis] = s[i] - '0';
		}
	}
	sort(a + 1, a + vis + 1);
	for (int i = vis; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
