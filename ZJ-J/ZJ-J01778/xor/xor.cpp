#include <bits/stdc++.h>
using namespace std;
bool mode1 = 1, mode2 = 1, mode3 = 1;
long long n, k, a[500005], ans, b[500005];
bool v[500005];
void solve1() {
	cout << n / 2;
	return;
}
void solve2() {
	int cnt = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) ans += (a[i] == 1);
	cout << ans;
	return;
}
void solve3() {
	int cnt = 0;
	ans = 0;
	vector<int> q;
	if (a[n] == 0) ans++;
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) ans++;
		else {
			if (a[i] == 1 and a[i + 1] == 1) ans++, i++;
		}
	}
	cout << ans;
	return;
}
bool chk(int l, int r) {
	for (int i = l; i <= r; i++) 
		if (v[i] == 1) return 0;
	for (int i = l; i <= r; i++) v[i] = 1;
	return 1;
}
void solve5() {
	for (int i = 2; i <= n; i++) {
		b[i] = a[i];
		b[i] ^= b[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((b[j] ^ b[j - i]) == k and chk(j - i + 1, j)) {
				ans++;
				j += i - 1;
			}
		}
	}
	cout << ans;
	return;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) mode1 = 0;
		if (a[i] > 1) mode2 = 0;
		if (a[i] > 255) mode3 = 0;
	} 
	if (mode1) {
		solve1();
	}
	else if (mode2) {
		if (k == 1) solve2();
		else solve3();
	}
	else if (mode3) {
		solve5();
	}
	else {
		solve5();
	}
	return 0;
}
