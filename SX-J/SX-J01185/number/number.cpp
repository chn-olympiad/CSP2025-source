#include <bits/stdc++.h>
using namespace std;
string s;
int a[10000000], cnt = 0, c0 = 0;
bool f = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int ls = s.size();
	for (int i = 0; i < ls; i++) {
		if (s[i] >= '1' && s[i] <= '9') {
			a[i] = s[i] - '0';
			cnt++;
		} else if (s[i] == '0') {
			c0++;
		}
	}
	sort(a, a + ls);
	for (int i = ls; i >= 0; i--) {
		if (a[i] != 0) {
			cout << a[i];
		}
	}
	for (int i = c0; i > 0; i--) {
		cout << 0;
	}

	return 0;
}
