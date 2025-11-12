#include <bits/stdc++.h>
using namespace std;
string s;
long long n, a[1000005], l, b;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[n] = s[i] - '0';
			n++;
		}
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
