#include <bits/stdc++.h>
using namespace std;
int n, a[5005], C[5005][5005], ans;
bool flag[5005];
const int mod = 998244353;

void dfs(int num, int s, int len, int maxx, int lst) {
	if (s == num) {
		if (len > maxx * 2) {
			ans = (ans + 1 + mod) % mod;
		}
		return ;
	}
	for (int i = lst; i <= n; i++) {
		if (flag[i] == 1)
			continue;
		flag[i] = 1;
		dfs(num + 1, s, len + a[i], max(maxx, a[i]), i);
		flag[i] = 0;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int maxx = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	if (maxx == 1) {
		C[0][0] = 1, C[1][0] = C[1][1] = 1;
		for (int i = 2; i <= n; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
		for (int i = 3; i <= n; i++) {
			ans = (ans + C[n][i] + mod) % mod;
		}
		cout << ans << endl;
	} else {
		for (int i = 3; i <= n; i++) {
			dfs(0, i, 0, 0, 1);
		}
		cout << ans << endl;
	}
	return 0;
}
