#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], a1[500005], a2[500005], nu, ans = INT_MIN;
map <int, map <int, int> > f;

int y(int a, int b) {
	if (a == b)
		return a;
	int s = 0, nu = 1;
	while (a > 0 or b > 0) {
		if (a % 2 != b % 2)
			s += nu;
		nu *= 2;
		a /= 2;
		b /= 2;
	}
	return s;
}

void dfs(int cnt, int num) {
	if (cnt == nu) {
		ans = max(num, ans);
		return;
	}
	for (int i = cnt + 1; i <= nu; i++) {
		if (a2[cnt] < a1[i])
			dfs(i, num + 1);
	}
	return;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = a[i];
		if (f[i][i] == k) {
			a1[++nu] = i;
			a2[nu] = i;
		}
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = y(f[i][j - 1], a[j]);
			if (f[i][j] == k) {
				a1[++nu] = i;
				a2[nu] = j;
			}
		}
	}
	for (int i = 1; i <= nu; i++) {
		dfs(i, 1);
	}
	cout << ans;
	return 0;
}
