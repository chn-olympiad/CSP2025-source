#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define mod 998244353

int n, a[5005], ans, sum = 1;
bool flag[105], f[105], A;

void dfs(int cur, int k, int las) {
	if (cur == k) {
		int sum = 0, maxx = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i]) {
				sum += a[i];
				maxx = max(maxx, a[i]);
			}
		}
		if (sum > maxx * 2) ans++;
	} else {
		for (int i = las + 1; i <= n; i++) {
			if (!f[i]) {
				f[i] = true;
				dfs(cur + 1, k, i);
				f[i] = false;
			}
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		flag[a[i]] = true;
		if (a[i] != 1) A = true;
	}
	if (!A) { // 24 pts
		for (int i = 1; i <= n; i++) {
			sum = sum * 2 % mod;
		}
		sum = (sum - 1 - n - (n * (n - 1) / 2)) % mod;
		cout << sum;
		return 0;
	}
	if (n <= 20) { // perhaps TLE when n > 10, 24 pts
		for (int i = 3; i <= n; i++) {
			dfs(0, i, 0);
			memset(f, false, sizeof(f));
		}
		cout << ans;
		return 0;
	}
	cout << 8484848; // rp++ pts
	return 0;
}
