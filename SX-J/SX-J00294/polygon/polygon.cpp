#include <bits/stdc++.h>
using namespace std;
long long a[5010];
long long ans = 0;

void dfs(int s, int k, int l) {
	if (k > s && l >= 3) {
		ans++;
		return ;
	}
	for (int i = s - 1; i >= 1; i--) {
		dfs(i, k + a[i], l + 1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n == 3) {
		if (a[3] < a[1] + a[2]) {
			cout << 1;
		} else
			cout << 0;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		dfs(a[i], 0, 1);
	}
	cout << (ans % 998224353) - 1;
	return 0;
}
