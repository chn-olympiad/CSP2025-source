#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> m >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int leng = s.size();
	for (int i = 0; i < leng; i++) {
		if (s[i] == '0') {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				a[j] -= 1;
			}
			for (int j = 1; j <= n; j++) {
				if (a[j] <= 0)
					a[j + 1] -= 1;
			}
			for (int j = 1; j <= n; j++) {
				if (a[j] <= 0)
					cnt++;
			}
			if (cnt >= n) {
				long long ans = 1;
				for (int j = cnt; j >= 1; j--) {
					ans *= j;
				}
				cout << ans;
			} else if (n - cnt > 0) {
				long long ans = 1;
				for (int j = 1; j <= n - cnt; j++) {
					ans *= j;
				}
				cout << ans;
			} else {
				long long ans = 1;
				for (int j = cnt; j >= 1; j--) {
					ans *= j;
				}
				cout << ans;
			}
		}
	}
	return 0;
}