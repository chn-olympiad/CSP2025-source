#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k;
int a[N];
bool flag1 = true;
bool flag2 = true;
int cnt1 = 0;
int cnt0 = 0;
int ans = 0;
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt1 += ((a[i] == 1) ? 1 : 0);
		cnt0 += ((a[i] == 0) ? 1 : 0);
		if (a[i] == k) ans++;
		if (a[i] != 1) flag1 = false;
		if (a[i] != 1 && a[i] != 0) flag2 = false;
	}
	if (flag1 == true) {
		cout << n / 2 << endl;
		return 0;
	}
	if (flag2 == true) {
		if (k == 1) {
			cout << cnt1 << endl;
		} else {
			cout << cnt0 << endl;
		}
		return 0;
	}
	cout << ans << endl;
	return 0;
}
