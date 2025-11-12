#include <bits/stdc++.h>
#define ll long long
#define Fcin; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 10;
struct node {
	int x, y, z;
}a[N];
bool cmp (node x, node y) {
	if (x.x == y.x) {
		if (x.y == y.y) return x.z > y.z;
		else return x.y > y.y;
	}
	return x.x > y.x;
}
int maxn, n;
void dfs (int step1, int step2, int step3, int step, int ans) {
	if ((step1 - 1) > n / 2) return;
	if ((step2 - 1) > n / 2) return;
	if ((step3 - 1) > n / 2) return;
	if (step == n + 1) {
		maxn = max (maxn, ans);
		return;
	}
	dfs (step1 + 1, step2, step3, step + 1, ans + a[step].x);
	dfs (step1, step2 + 1, step3, step + 1, ans + a[step].y);
	dfs (step1, step2, step3 + 1, step + 1, ans + a[step].z);
	return;	
}
int main () {        
	Fcin;
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort (a + 1, a + n + 1, cmp);
		if (a[n].y == 0 && a[n].z == 0 && a[1].y == 0 && a[1].z == 0) {
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)
			  ans += a[i].x;
			cout << ans << "\n";
			continue;
		}
		maxn = 0;
		dfs (1, 1, 1, 1, 0);
		cout << maxn << "\n";
	}
	return 0;
}

