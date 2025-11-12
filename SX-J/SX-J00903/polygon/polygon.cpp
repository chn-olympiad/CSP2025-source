#include <bits/stdc++.h>
using namespace std;
int n, a[10010], f1, cnt;
long long w[10010];

long long jie(int a, int b) {
	long long sum = 1;
	for (int i = b; i <= a; i++)
		sum  = i * sum;
	return sum;
}

bool p(int e) {
	long long sum = 0, ma = 0;
	for (int i = 1; i <= e; i++) {
		sum += w[i];
		ma = max(w[i], ma);
	}
	return ma * 2 < sum;
}

int dfs(int d, int x, int e) {
	if (x > e) {
		if (p(e))
			return 1;
		return 0;
	}
	long long sum = 0;
	for (int i = d; i <= n - e + x; i++) {
		w[x] = a[i];
		sum += dfs(i + 1, x + 1, e);
	}
	return sum;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon,out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			f1 = 1;
	}
	if (!f1) {
		long long sum = 0;
		for (int i = 3; i <= n; i++) {
			sum += jie(n, n - i + 1) / jie(i, 2) % 998244353;
		}
		cout << sum % 998244353;
	} else {
		long long cnt = 0;
		for (int i = 3; i <= n; i++) {
			cnt += dfs(1, 1, i) % 998244353;
		}
		cout << cnt % 998244353 ;
	}
	return 0;
}
