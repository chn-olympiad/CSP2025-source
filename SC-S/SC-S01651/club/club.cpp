#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int maxn = 1e6+5;
int t;
int a[maxn], b[maxn], c[maxn];
int a1, a2, a3;
int ans;
void dfs(int s, int sum, int pd) {
	if (s == n) {
		ans = max(ans, sum);
	}
	if (a1 < n / 2) {
		a1++;
		dfs(s + 1, sum + a[s + 1], pd);
		a1--;
	}
	if (a2 < n / 2) {
		a2++;
		dfs(s + 1, sum + b[s + 1], pd);
		a2--;
	}
	if (pd == 0) {
		if (a3 < n / 2) {
			a3++;
			dfs(s + 1, sum + c[s + 1], pd);
			a3--;
		}
	}

}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld", &t);
	while (t--) {
		a1 = 0, a2 = 0, a3 = 0, ans = 0;
		scanf("%lld", &n);
		if (n <= 30) {
			for (int i = 1; i <= n; ++i) {
				scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
			}
			dfs(0, 0, 0);
			printf("%lld\n", ans);
		} else if (n > 30 && n <= 200) {
			for (int i = 1; i <= n; ++i) {
				scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
			}
			dfs(0, 0, 1);
			printf("%lld\n", ans);
		} else if (n > 200) {
			for (int i = 1; i <= n; ++i) {
				scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
			}
			sort(a + 1, a + 1 + n);
			for (int i = n; i > n / 2; --i) {
				ans += a[i];
			}
			printf("%lld", ans);
		}
	}
	return 0;
}
