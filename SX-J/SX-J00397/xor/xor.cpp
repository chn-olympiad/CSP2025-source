#include <bits/stdc++.h>
using namespace std;
int a[500005], s[500005];

bool f(bool a, bool b) {
	return (a || b) - (a&&b);
}

int ff(int a, int b) {
	int sum = 0;
	for (int i = 0; a != 0 || b != 0; i++) {
		sum += pow(2, i) * f(a % 2, b % 2);
		a /= 2;
		b /= 2;
	}
	return sum;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = ff(s[i - 1], a[i]);
	}
	int cnt = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = cnt; j <= i; j++) {
			if (ff(s[i], s[j - 1]) == m) {
				cnt = i + 1;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}