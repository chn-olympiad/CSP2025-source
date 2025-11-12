#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e5 + 50;
int t;
int n, a[N][5];
ll ans;
ll dp1[N], dp2[N], dp3[N];
void dfs(int now, int n1, int n2, int n3, int s1, int s2, int s3) {
	if (now > n) {
		ans = max(ans, (ll)n1 + n2 + n3);
		return;
	}
	if (dp1[now] >= n1 && dp2[now] >= n2 && dp3[now] >= n3) return;
	dp1[now] = n1;
	dp2[now] = n2;
	dp3[now] = n3;
	if (s1 < n / 2) dfs(now + 1, n1 + a[now][1], n2, n3, s1 + 1, s2, s3);
	if (s2 < n / 2) dfs(now + 1, n1, n2 + a[now][2], n3, s1, s2 + 1, s3);
	if (s3 < n / 2) dfs(now + 1, n1, n2, n3 + a[now][3], s1, s2, s3 + 1);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> t;
	while (t--) {
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		memset(dp3, -1, sizeof(dp3));
		cin >> n;
		ans = -1;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, 0, 0, 0, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}//fuck ccf 
