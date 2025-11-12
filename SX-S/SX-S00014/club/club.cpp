#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int t, n, a[maxn][5], an;
int z1, z2, z3, maxx[maxn], px[maxn];
bool vis[maxn];

int solve1(int r1, int r2, int r3) {
	int da = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		px[i] = a[i][1];
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r1; i--) {
		da = da + px[i];
		for (int j = 1; j <= n; j++)
			if (px[i] == a[j][1]) {
				vis[j] = 1;
				break;
			}
	}//1

	for (int i = 1; i <= n; i++) {
		px[i] = a[i][2];
		if (vis[i] == 1)
			px[i] = -1;
	}
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r2; i--) {
		da = da + px[i];
		for (int j = 1; j <= n; j++)
			if (px[i] == a[j][2]) {
				vis[j] = 1;
				break;
			}
	}//2

	if (r3 == 0)
		return da;
	for (int i = 1; i <= n; i++) {
		px[i] = a[i][3];
		if (vis[i] == 1)
			px[i] = -1;
	}
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r3; i--) {
		da = da + px[i];
	}//3

	return da;
}

int solve2(int r1, int r2, int r3) {
	int da = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		px[i] = a[i][2];
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r2; i--) {
		da = da + px[i];
		for (int j = 1; j <= n; j++)
			if (px[i] == a[j][2]) {
				vis[j] = 1;
				break;
			}
	}//2

	for (int i = 1; i <= n; i++) {
		px[i] = a[i][1];
		if (vis[i] == 1)
			px[i] = -1;
	}
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r1; i--) {
		da = da + px[i];
		for (int j = 1; j <= n; j++)
			if (px[i] == a[j][1]) {
				vis[j] = 1;
				break;
			}
	}//1

	if (r3 == 0)
		return da;
	for (int i = 1; i <= n; i++) {
		px[i] = a[i][3];
		if (vis[i] == 1)
			px[i] = -1;
	}
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r3; i--) {
		da = da + px[i];
	}//3

	return da;
}

int solve3(int r1, int r2, int r3) {
	int da = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		px[i] = a[i][3];
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r3; i--) {
		da = da + px[i];
		for (int j = 1; j <= n; j++)
			if (px[i] == a[j][3]) {
				vis[j] = 1;
				break;
			}
	}//1

	for (int i = 1; i <= n; i++) {
		px[i] = a[i][2];
		if (vis[i] == 1)
			px[i] = -1;
	}
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r2; i--) {
		da = da + px[i];
		for (int j = 1; j <= n; j++)
			if (px[i] == a[j][2]) {
				vis[j] = 1;
				break;
			}
	}//2

	if (r3 == 0)
		return da;
	for (int i = 1; i <= n; i++) {
		px[i] = a[i][3];
		if (vis[i] == 1)
			px[i] = -1;
	}
	sort(px + 1, px + 1 + n);
	for (int i = n; i > n - r3; i--) {
		da = da + px[i];
	}//3

	return da;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		an = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			int s1 = a[i][1];
			int s2 = a[i][2];
			int s3 = a[i][3];
			int mmax = max(s1, s2);
			mmax = max(mmax, s3);
			if (mmax == a[i][1]) {
				z1++;
				maxx[i] = a[i][1];
			}
			if (mmax == a[i][2]) {
				z2++;
				maxx[i] = a[i][2];
			}
			if (mmax == a[i][3]) {
				z3++;
				maxx[i] = a[i][3];
			}
		}
		//printf("%d %d %d\n", z1, z2, z3); //dethsertheastrhaertgsrgtearyha
		if (z1 <= n / 2 && z2 <= n / 2 && z3 <= n / 2)
			for (int i = 1; i <= n; i++)
				an = an + maxx[i];
		else
			for (int i = 1; i <= n / 2; i++)
				for (int j = 1; j <= n / 2; j++) {
					//printf("%d %d %d %d\n", an, solve1(i, j, n - i - j), solve2(i, j, n - i - j), solve3(i, j, n - i - j));
					an = max(an, solve1(i, j, n - i - j));
					an = max(an, solve2(i, j, n - i - j));
					an = max(an, solve3(i, j, n - i - j));
				}

		printf("%d\n", an);
	}
	return 0;
}
