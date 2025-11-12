#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long l1 = 0, l2 = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			l1++;
		}
	}
	long long  a[l1 + 3] = {0};
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[l2] = s[i] - '0';
			l2++;
		}
	}
	sort(a + 1, a + l1 + 1);
	for (int i = l1; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
