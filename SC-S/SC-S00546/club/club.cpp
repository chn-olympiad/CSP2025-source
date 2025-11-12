#include<bits/stdc++.h>
using namespace std;

const int N = 210;

int f[N][N >> 1][N >> 1];
int a[N][5], tmp[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, T;
	scanf("%d", &T);
	while(T--) {
		memset(f, 0, sizeof(f));
		scanf("%d", &n);
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			tmp[i] = a[i][1];
			if(a[i][2] != 0 || a[i][3] != 0) flag = false;
		}
		if(flag) {
			int sum = 0;
			sort(tmp + 1, tmp + 1 + n, greater<int>());
			for(int i = 1; i <= (n >> 1); i++) {
				sum = sum + tmp[i];
			}
			printf("%d", sum);
			return 0;
		}
		for(int i = 0; i <= (n >> 1); i++) {
			for(int j = 0; j <= (n >> 1); j++) {
				f[0][i][j] = -2e9;
			}
		}
		f[0][0][0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= min((n >> 1), i); j++) {
				for(int k = 0; k <= min((n >> 1), i); k++) {
					if(j + k > i) continue;
					int l = i - j - k; 
					if(l > (n >> 1)) continue;
					if(j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][1]);
					if(k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
					if(l > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i <= (n >> 1); i++) {
			for(int j = 0; j <= (n >> 1); j++) {
				ans = max(ans, f[n][i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}