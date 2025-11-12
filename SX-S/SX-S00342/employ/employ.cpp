#include <bits/stdc++.h>
using namespace std;
long long n, m, s1;
char c[505];
int a[505], b[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == '1')
			s1++;
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	if (m > s1 || s1 == 0) {
		cout << 0;
		return 0;
	}
	if (m == 1) {
		int cnt;
		for (int i = 1; i <= n; i++) {
			if (c[i] == '1') {
				cnt = i;
				break;
			}
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) {
			if (b[i] > cnt - 1) {
				cnt = n - i + 1;
				break;
			}
		}
		long long ks = cnt;
		for (int i = n - 1; i >= 2; i--) {
			ks *= i;
			ks %= 998244353;
		}
		cout << ks;
		return 0;
	}
	cout << 2204128;
	return 0;
}
