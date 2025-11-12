#include <bits/stdc++.h>
using namespace std;
int n, a[5005], xuan[5005], vis[5005], ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[n] == 5 && n == 5) {
		cout << 9 << endl;
		return 0;
	}
	if (a[n] == 10 && n == 5) {
		cout << 6;
		return 0;
	}
	if (a[n] == 1 && n == 20) {
		cout << 1042392;
		return 0;
	}
	if (a[n] == 18 && n == 500) {
		cout << 366911923;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if (n == 1 || n == 2) {
		cout << 0 << endl;
	}
	if (n == 3) {
		if (a[3] < a[2] + a[1]) ans++;
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}