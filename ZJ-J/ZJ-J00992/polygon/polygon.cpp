#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010];
int b[30], l;
int f[510][10][510];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n <= 20) {
		int ans = 0;
		for (int i = 1; i < (1 << n); ++i) {
			l = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					b[++l] = j+1;
			int sum = 0, mx = 0;
			for (int j = 1; j <= l; j++)
				sum += a[b[j]], mx = max(mx, a[b[j]]);
			if (sum > 2*mx && l >= 3)
				ans++;
		}
		printf("%d", ans%998244353);
	} else {
		if (n <= 500) {
			bool ok = true;
			for (int i = 1; i <= n; i++)
				if (a[i] > 1) {
					ok = false;
					break;
				}
			if (ok) {
				f[0][a[1]][a[1]] = 1;
				f[0][0][0] = 1;
				for (int i = 0; i <= n; i++)
					for (int j = 0; j <= 1; j++)
						for (int k = 1; k <= 500; k++)
							if (f[i][j][k]) {
								f[i+1][max(a[i+1], j)][k+a[i+1]]++;
								f[i+1][max(a[i+1], j)][k+a[i+1]] %= 998244353;
								f[i+1][j][k]++;
								f[i+1][j][k] %= 998244353;
							}
				int sum = 0;
				for (int j = 0; j <= 1; j++)
					for (int k = j*2+1; k <= 500; k++)
						sum = (0LL+sum+f[n][j][k])%998244353;
				printf("%d", sum);
				return 0;
			}
		}
		puts("0");
	}
}
