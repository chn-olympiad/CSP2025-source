#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N][3], cnt[3], sum[3], ans;
void dfs(int u) {
	if (u > n) {
		ans = max(ans, sum[0] + sum[1] + sum[2]);
		return;
	}
	for (int i = 0; i <= 2; i ++ ) {
		if (cnt[i] < n / 2) {
			cnt[i] ++ ;
			sum[i] += a[u][i];
			dfs(u + 1);
			cnt[i] -- ;
			sum[i] -= a[u][i];
		}
	}
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T -- ) {
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 0; j <= 2; j ++ ) {
				scanf("%d", &a[i][j]);
			}
		}
		if (n <= 16) {
			dfs(1);
			printf("%d\n", ans);
		}
		else {
			bool is_00 = true;
			for (int i = 1; i <= n; i ++ ) {
				if (a[i][1] != 0 || a[i][2] != 0) {
					is_00 = false;
					break;
				}
			}
			if (is_00) {
				vector<int> q;
				for (int i = 1; i <= n; i ++ ) {
					q.push_back(a[i][0]);
				}
				sort(q.begin(), q.end());
				reverse(q.begin(), q.end());
				for (int i = 0; i < n / 2; i ++ ) {
					ans += q[i];
				}
				printf("%d\n", ans); 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
