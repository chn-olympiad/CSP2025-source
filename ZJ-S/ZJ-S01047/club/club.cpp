#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

struct info {
	int x, y;
	bool operator < (const info &a) {
		return max(x, y) > max(a.x, a.y);
	}
} tmp[N];

int t;
int n, a[N][3];
int f[610][310][310];
int tmp2[N];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		if (n <= 600) {
			memset(f, 0xff, sizeof f);
			f[0][0][0] = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j <= n>>1; j++)
					for (int k = 0; k <= n>>1; k++)
						if (i-j-k <= (n>>1) && f[i][j][k] != -1) {
							f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k]+a[i+1][0]);
							f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k]+a[i+1][1]);
							f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k]+a[i+1][2]);
						}
			int ans = INT_MIN;
			for (int j = 1; j <= n>>1; j++)
				for (int k = 1; k <= n>>1; k++)
					if (n-j-k <= (n>>1))
						ans = max(ans, f[n][j][k]);
			printf("%d\n", ans);
		} else {
			bool f = true;
			for (int i = 1; i <= n; i++)
				if (a[i][2] > 0) {
					f = false;
					break;
				}
			if (f) {
				int sum = 0;
				for (int i = 1; i <= n; i++)
					tmp[i].x = a[i][0], tmp[i].y = a[i][1];
				sort(tmp+1, tmp+n+1);
				for (int i = 1; i <= n>>1; i++)
					sum += max(tmp[i].x, tmp[i].y);
				for (int i = (n>>1)+1; i <= n; i++)
					sum += min(tmp[i].x, tmp[i].y);
				printf("%d\n", sum);
			} else {
				f = true;
				for (int i = 1; i <= n; i++)
					if (a[i][1] > 0) {
						f = false;
						break;
					}
				if (f) {
					for (int i = 1; i <= n; i++)
						tmp2[i] = a[i][0];
					sort(tmp2+1, tmp2+n+1, cmp);
					int sum = 0;
					for (int i = 1; i <= n>>1; i++)
						sum += tmp2[i];
					printf("%d\n", sum);
				} else {
					puts("0");
				}
			}
		}
	}
}
