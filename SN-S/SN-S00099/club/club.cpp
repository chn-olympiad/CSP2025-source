#include <bits/stdc++.h>
using namespace std;
const int XN=1e5+10;
int t, n, ans, s[XN];
struct node {
	int x, y, z;
} a[XN];
void dfs(int cnt, int c1, int c2, int c3, int sum) {
	if (cnt > n) {
		ans = max(ans, sum);
		return;
	}
	if (sum+s[n]-s[cnt-1] <= ans)
		return;
	if (a[cnt].x>=a[cnt].y && a[cnt].x>=a[cnt].z) {
		if (c1 < n/2) dfs(cnt+1, c1+1, c2, c3, sum+a[cnt].x);
		if (a[cnt].y >= a[cnt].z) {
			if (c2 < n/2) dfs(cnt+1, c1, c2+1, c3, sum+a[cnt].y);
			if (c3 < n/2) dfs(cnt+1, c1, c2, c3+1, sum+a[cnt].z);
		} else {
			if (c3 < n/2) dfs(cnt+1, c1, c2, c3+1, sum+a[cnt].z);
			if (c2 < n/2) dfs(cnt+1, c1, c2+1, c3, sum+a[cnt].y);
		}
	} else if (a[cnt].y>=a[cnt].x && a[cnt].y>=a[cnt].z) {
		if (c2 < n/2) dfs(cnt+1, c1, c2+1, c3, sum+a[cnt].y);
		if (a[cnt].x >= a[cnt].z) {
			if (c1 < n/2) dfs(cnt+1, c1+1, c2, c3, sum+a[cnt].x);
			if (c3 < n/2) dfs(cnt+1, c1, c2, c3+1, sum+a[cnt].z);
		} else {
			if (c3 < n/2) dfs(cnt+1, c1, c2, c3+1, sum+a[cnt].z);
			if (c1 < n/2) dfs(cnt+1, c1+1, c2, c3, sum+a[cnt].x);
		}
	} else {
		if (c3 < n/2) dfs(cnt+1, c1, c2, c3+1, sum+a[cnt].z);
		if (a[cnt].x >= a[cnt].y) {
			if (c1 < n/2) dfs(cnt+1, c1+1, c2, c3, sum+a[cnt].x);
			if (c2 < n/2) dfs(cnt+1, c1, c2+1, c3, sum+a[cnt].y);
		} else {
			if (c2 < n/2) dfs(cnt+1, c1, c2+1, c3, sum+a[cnt].y);
			if (c1 < n/2) dfs(cnt+1, c1+1, c2, c3, sum+a[cnt].x);
		}
	}
//	if (c1 < n/2) dfs(cnt+1, c1+1, c2, c3, sum+a[cnt].x);
//	if (c2 < n/2) dfs(cnt+1, c1, c2+1, c3, sum+a[cnt].y);
//	if (c3 < n/2) dfs(cnt+1, c1, c2, c3+1, sum+a[cnt].z);
	return;
}
bool cmp(node a, node b) {
	return min(a.x, a.y)>min(b.x, b.y);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool f=1; 
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].z != 0) f = 0;
			s[i] = s[i-1]+max({a[i].x, a[i].y, a[i].z});
		}
		if (n <= 500) {
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		} else {
			if (f) {
				sort(a+1, a+n+1, cmp); int sum=0;
				for (int i = 1; i <= n; i++)
					sum += max(a[i].x, a[i].y);
				cout << sum << "\n";
			} else {
				int sum=0;
				for (int i = 1; i <= n; i++)
					sum += max({a[i].x, a[i].y, a[i].z});
				cout << sum << "\n";
			}
		}
	}
	return 0;
}
