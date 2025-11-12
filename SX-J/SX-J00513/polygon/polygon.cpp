#include <bits/stdc++.h>
using namespace std;
int n, a[5005], x, s[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 2; j <= n; j++) {
			int ans = s[j] - s[i - 1];
			if (ans > 2 * a[j]) {
				x = (x + 1) % 998244353;
				for (int b = i + 1; b <= j - 1; b++) {
					for (int c = b; c <= j - 1; c++) {
						int cnt = s[c] - s[b - 1];
						if (ans - cnt > 2 * a[j])
							x = (x + 1) % 998244353;
					}
				}
			}
		}
	}
	cout << x;
}
