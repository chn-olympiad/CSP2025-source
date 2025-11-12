#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, h;
int a1[N], a2[N], a3[N], cnt[4];
bool vis[N];
long long ans;
bool v2, v3;

void dfs2(int p, long long as) {
	if (p > n) {
		ans = max(ans, as);
		return;
	}
	if (cnt[1] < h) {
		cnt[1]++;
		int nx = p + 1;
		dfs2(nx, as + a1[p]);
		cnt[1]--;
	}
	if (cnt[2] < h) {
		cnt[2]++;
		int nx = p + 1;
		dfs2(nx, as + a2[p]);
		cnt[2]--;
	}
	if (cnt[3] < h) {
		cnt[3]++;
		int nx = p + 1;
		dfs2(nx, as + a3[p]);
		cnt[3]--;
	}
}

void dfs1(int p, long long as) {
	if (p > n) {
		ans = max(ans, as);
		return;
	}
	if (cnt[1] < h) {
		cnt[1]++;
		int nx = p + 1;
		dfs1(nx, as + a1[p]);
		cnt[1]--;
	}
	if (cnt[2] < h) {
		cnt[2]++;
		int nx = p + 1;
		dfs1(nx, as + a2[p]);
		cnt[2]--;
	}
}

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		v3 = 0, v2 = 0;
		for (int i = 1; i <= n; i++) {
			a1[i] = 0, a2[i] = 0, a3[i] = 0;
		}
		scanf("%d", &n);
		h = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
			if (a2[i])
				v2 = 1;
			if (a3[i])
				v3 = 1;
		}
		if (!v2 && !v3) {
			sort(a1 + 1, a1 + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += a1[i];
		} else if (v2 && !v3) {
			dfs1(1, 0);
		} else {
			dfs2(1, 0);
		}
		printf("%ld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}