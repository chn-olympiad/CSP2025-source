#include <bits/stdc++.h>
using namespace std;
int t[102], n, k, minn = 100, maxx = -1, s1 = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		if (t[i] == 1)
			s1++;
		if (minn > t[i])
			minn = t[i];
		if (maxx < t[i])
			maxx = t[i];
	}
	if (minn == 1 && maxx == 1 && k == 0) {
		cout << n / 2;
		return 0;
	}
	if (minn == 0 && maxx == 1 && k == 1) {
		cout << s1;
		return 0;
	}
	if (minn == 0 && maxx == 1 && k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (t[i] == 0)
				ans++;
			if (t[i] == 1 && t[i + 1] == 1) {
				ans++;
				i++;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
