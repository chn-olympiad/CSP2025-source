#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1000;

struct ooo {
	int x, y, z, f, s;
	bool d12 = false, d23 = false, d13 = false;
} a[maxn];

int T, n, mx, x, y, z;
long long ans;
/*mx, 单个社团最大人数, zan, 暂留answer*/
bool d[maxn], A = 1, B = 1;

void dfs(int side, long long zan) {

	if (x < mx && side <= n && (a[side].x == a[side].f || a[side].x == a[side].s)) {
		x++;
		dfs(side + 1, zan + a[side].x);
		x--;
	}
	if (y < mx && side <= n && (a[side].y == a[side].f || a[side].y == a[side].s)) {
		y++;
		dfs(side + 1, zan + a[side].y);
		y--;
	}
	if (z < mx && side <= n && (a[side].z == a[side].f || a[side].z == a[side].s)) {
		z++;
		dfs(side + 1, zan + a[side].z);
		z--;
	}
	if (side == n + 1) {
		ans = max(ans, zan);
		return;
	}
}

bool cmd1(ooo x, ooo y) {
	return x.x <= y.x;
}

bool cmd2(ooo x, ooo y) {
	return x.y <= y.y;
}

bool cmd3(ooo x, ooo y) {
	return x.z <= y.z;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		x = 0, y = 0, z = 0, ans = 0;
		scanf("%d", &n), mx = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			a[i].f = max(a[i].x, max(a[i].y, a[i].z));
			a[i].s = a[i].x + a[i].y + a[i].z - a[i].f - min(a[i].x, min(a[i].y, a[i].z));
			if (a[i].y != 0)
				A = false;
			if (a[i].z != 0)
				B = false;
		}
		if (A && B) {
			sort(a + 1, a + n + 1, cmd1);
			for (int i = 1; i <= mx; i++) {
				ans += a[i].x;
			}
		} else
			dfs(1, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
