#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
long long n, a[50100], sum, l, f, db[5010];

void dfs(int k, int s, int need, int l, int j) {
	if (f == 1) {
		return;
	}
	if (s > need) {
		sum = (sum % N + db[l] % N) % N;
		sum = sum % N;
		f = 1;
		return;
	}
	if (k == j) {
		f = 1;
		return;
	}
	for (int i = l - 1; i >= 1; i--) {
		dfs(k + 1, s + a[i], need, i, j);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int t = 1;
	for (int i = 1; i <= n; i++) {
		t = t * i % N;
		db[i] = t % N;
	}
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		l = i;
		f = 0;
		dfs(1, a[i], a[i] * 2, l, i);
	}
	cout << sum % N - 1;
	return 0;
}