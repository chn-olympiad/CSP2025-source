#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int T, n, a[maxn][4], cnt[4];
long long ans = 0;
void dfs(int i, long long res) {
	if (i > n) {
		ans = max(ans, res);
		return ;
	}
	for (int j = 1; j <= 3; j++) {
		if (cnt[j] == n / 2) continue;
		cnt[j]++;
		dfs(i + 1, res + a[i][j]);
		cnt[j]--;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		bool can1 = true, can2 = true, can3 = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &a[i][j]);
				if (j == 1 && a[i][j]) can1 = false;
				if (j == 2 && a[i][j]) can2 = false;
				if (j == 3 && a[i][j]) can3 = false;				
			}
		ans = 0;
		if (n <= 10) {
			memset(cnt, 0, sizeof cnt);
			dfs(1, 0);
			printf("%lld\n", ans);
			continue;		
		}
		if (can2 && can3) {
			vector<int> v;
			for (int i = 1; i <= n; i++)
				v.push_back(a[i][1]);
			sort(v.begin(), v.end(), [&](int g, int h) {
				return g > h;
			});
			for (int i = 0; i < n / 2; i++)
				ans += v[i];
			printf("%lld\n", ans);
			continue;
		}
		if (can1 && can3) {
			vector<int> v;
			for (int i = 1; i <= n; i++)
				v.push_back(a[i][2]);
			sort(v.begin(), v.end(), [&](int g, int h) {
				return g > h;
			});
			for (int i = 0; i < n / 2; i++)
				ans += v[i];
			printf("%lld\n", ans);
			continue;
		}
		if (can1 && can2) {
			vector<int> v;
			for (int i = 1; i <= n; i++)
				v.push_back(a[i][3]);
			sort(v.begin(), v.end(), [&](int g, int h) {
				return g > h;
			});
			for (int i = 0; i < n / 2; i++)
				ans += v[i];
			printf("%lld\n", ans);
			continue;
		}
	}
	return 0;
}