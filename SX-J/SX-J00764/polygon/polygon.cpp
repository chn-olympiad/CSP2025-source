#include <bits/stdc++.h>
using namespace std;
long long s[5005];

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	long long n, f, cnt = 0, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] <= s[i + 1]) {
			f = s[i];
			s[i] = s[i + 1];
			s[i + 1] = f;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n - 1; j++) {

		}
	}
	cout << cnt;
	return 0;
}
