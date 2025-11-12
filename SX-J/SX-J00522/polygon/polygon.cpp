#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int a[N], v[N], h[N];
long long n, k, cnt = 0;

void print() {
	long long sum = 0, maxv = LLONG_MIN;
	for (int i = 1; i <= k; i++) {
		sum = sum + h[i];
		maxv = max(h[i] * 1ll, maxv);
	}
	if (sum > maxv * 2)
		cnt++;
}

void dfs(int m, int k) {
	if (k == m + 1) {
		print();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			h[k] = a[i];
		}
		dfs(m + 1, k + 1);
		v[i] = 0;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long sum1 = 0, maxv1 = LLONG_MIN;
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 3) {
		for (int i = 1; i <= n; i++)
			sum1 = sum1 + a[i], maxv1 = max(a[i] * 1ll, maxv1);
		if (sum1 > maxv1 * 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	for (int i = 3; i <= n; i++)
		dfs(i, 1);
	cout << cnt;
	return 0;
}