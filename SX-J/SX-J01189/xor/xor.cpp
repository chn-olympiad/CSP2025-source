#include <bits/stdc++.h>
using namespace std;
int a[500005], ans, myans = 0;
int n, k, x = 1, f = 0;
int f1 = 0, f2 = 0, ss = 0;

void dfs(int step) {
	int sum = a[x];
	for (int i = x; i <= n; i++) {
		if (i != x) {
			sum = sum ^a[i];
		}
		if (sum == k) {
			f = 1;
			x = i + 1;
			ans++;
			myans = max(myans, ans);
			dfs(step + 1);
			ans--;
		}
	}
	if (f == 0) {
		x++;
		dfs(1);
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			ss++;
		if (a[i] != 1 && a[i] != 0)
			f2 = 1;
		if (a[i] != 1)
			f1 = 1;
	}
	if (f2 == 0) {
		cout << ss;
		return 0;
	}
	if (f1 == 0 && k == 0) {
		cout << ss / 2;
		return 0;
	}
	if (f1 == 0 && k == 1) {
		cout << ss;
		return 0;
	}
	dfs(1);
	cout << myans;
	return 0;
}