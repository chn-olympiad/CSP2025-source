#include <bits/stdc++.h>
using namespace std;
int n, a[114514], s[114514], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if ((s[i] - s[j]) > a[i] * 2)
				ans++;
		}
	}
	cout << ans * 3 << endl;
	return 0;
}
