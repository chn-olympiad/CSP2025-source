#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
struct node{
	int a, b, c;
}m[N], a[N], b[N], c[N];
int mx = 0;
void dfs(int k, int a, int b, int c, int ans) {
	if (a > n/2 || b > n/2 || c > n/2) return;
	if (k == n + 1) {
		mx = max(mx, ans);
		return;
	}
	dfs(k + 1, a + 1, b, c, ans + m[k].a);
	dfs(k + 1, a, b + 1, c, ans + m[k].b);
	dfs(k + 1, a, b, c + 1, ans + m[k].c);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a >> m[i].b >> m[i].c;
		}
		mx = 0;
		dfs(1, 0, 0, 0, 0);
		cout << mx << endl;
	}
	return 0;
} 