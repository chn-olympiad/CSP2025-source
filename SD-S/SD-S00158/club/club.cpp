#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][4];
bool vis[N];
int n, ans;
void dfs(int n1, int n2, int n3, int sum, int d) {
//	printf("%d %d %d %d\n",n1,n2,n3,sum);
	if(n1 > n/2 || n2 > n/2 || n3 > n/2)
		return;
	if(n1 + n2 + n3 == n) {
		ans = max(ans, sum);
		return;
	}

	dfs(n1+1, n2, n3, sum+a[d][1], d+1);
	dfs(n1, n2+1, n3, sum+a[d][2], d+1);
	dfs(n1, n2, n3+1, sum+a[d][3], d+1);
}
void solve() {
	ans = -1;
	memset(vis, 0, sizeof(vis));
	dfs(0, 0, 0, 0, 1);
	cout << ans << '\n';
}
bool check() {
	for(int i = 1; i <= n; i++)
		if(a[i][2]!= 0 || a[i][3] != 0)
			return 0;
	return 1;
}
void solveA() {
	ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i][1];
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(check())
			solveA();
		else
			solve();
	}
	return 0;
}
