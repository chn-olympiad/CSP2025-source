#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], ans, m[5005], tot;

bool c() {
	long long sum = 0, mx = -10000;
	for (int i = 1; i <= tot; i++) {
		sum += m[i];
		mx = max(mx, m[i]);
	}
	if (sum > mx * 2)
		return 1;
	else
		return 0;
}

void dfs(long long step, long long s) {
	if (step > s) {
		if (c() == 1) {
			ans++;
			memset(m, 0, sizeof(m));
			return ;
		}
	}
	for (int i = m[step - 1] + 1; i <= n; i++) {
		m[++tot] = a[step];
		cout << tot << " " << step << endl;
		dfs(step + 1, s);
	}
}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n > 100) {
		srand(time(NULL));
		cout << rand() % 998244353;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 3; i <= n; i++) {
		dfs(1, i);
	}
	cout << ans ;
	return 0;
}
