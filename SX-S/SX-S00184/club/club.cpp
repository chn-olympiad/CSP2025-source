#include <bits/stdc++.h>
using namespace std;
int n, t, a1, a2, a3;
long long allans = 0;
int a[310000][10];
pair<int, int> aa[3100000];
int p[100010][5];
bool b[100010];

void dfs(int dep, int cnt1, int cnt2, int cnt3, long long ans) {
	if (dep > n) {
		allans = max(allans, ans);
		return;
	}
	if (cnt1 + 1 <= n / 2) {
		dfs(dep + 1, cnt1 + 1, cnt2, cnt3, ans + a[dep][1]);
	}
	if (cnt2 + 1 <= n / 2) {
		dfs(dep + 1, cnt1, cnt2 + 1, cnt3, ans + a[dep][2]);
	}
	if (cnt3 + 1 <= n / 2) {
		dfs(dep + 1, cnt1, cnt2, cnt3 + 1, ans + a[dep][3]);
	}

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		allans = 0;
		cin >> n;
		int maxc = 0, maxb = 0;
		memset(b, false, sizeof(b));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1, &a2, &a3);
			a[i ][1] = a1;
			a[i ][2] = a2;
			a[i ][3] = a3;
			maxc = max(a3, maxc);
			maxb = max(a2, maxb);
		}
		if (maxb == 0 && maxc == 0) {
			for (int i = 1; i <= n / 2; i++) {
				allans += a[i][1];
			}
			printf("%lld\n", allans);
		} else {
			dfs(1, 0, 0, 0, 0);
			printf("%lld\n", allans);
		}

	}
	return 0;
}