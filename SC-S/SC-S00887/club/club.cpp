#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
ll t, n;
ll dp[N][5];
struct node {
	int x, y, z;
} a[N];
bool cmp(node a, node b) {
	return a.x > b.x;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int lim = n / 2;
		for (int i = 1; i <= n; i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a + 1, a + 1 + n, cmp);
		int ans = 0;
		for (int i = 1; i <= lim; i++)
			ans += a[i].x;
		cout << ans;
	}
	return 0;
}