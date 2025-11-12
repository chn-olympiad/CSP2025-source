#include <bits/stdc++.h>
using namespace std;
long long ans, sum;
int a[100010][5], t[5], mi[5];
int temp[100010], f[100010];
int n;

void chose(int i) {
	if (a[i][0] > a[i][1] && a[i][0] > a[i][2]) {
		t[0]++;
	} else if (a[i][1] > a[i][0] && a[i][1] > a[i][2]) {
		t[1]++;
	} else {
		t[2]++;
	}
}

int func(int j, int i) {
	if (i == 0) {
		return a[j][0] - max(a[j][1], a[j][2]);
	} else if (i == 1) {
		return a[j][1] - max(a[j][0], a[j][2]);
	} else {
		return a[j][2] - max(a[j][0], a[j][1]);
	}
	return 0;
}

void init() {
	ans = 0;
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	mi[0] = 0;
	mi[1] = 0;
	mi[2] = 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	}
	init();
	//若最优时i部门被满员限制
	for (int i = 0; i <= 2; i++) {
		sum = 0;
		//计算部门负收益
		for (int j = 1; j <= n; j++) {
			f[j] = func(j, i);
			sum += a[j][i];
		}
		//将负收益排序
		sort(f + 1, f + n + 1);
		for (int j = 1; j <= n / 2; j++) {
			sum -= f[j];
		}
		ans = max(ans, sum);
	}
	sum = 0;
	//若最优时没有满员限制
	for (int i = 1; i <= n; i++) {
		chose(i);
		sum += max(a[i][0], max(a[i][1], a[i][2]));
	}
	if (t[0] <= n / 2 && t[1] <= n / 2 && t[2] <= n / 2) {
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int tcase;
	scanf("%d", &tcase);
	for (int cas = 1; cas <= tcase; cas++) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}