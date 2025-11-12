#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int n, cnt1, cnt2, cnt3, ans, a[maxn][3], x[maxn], y[maxn], z[maxn], f[maxn];
bool cmp(int x, int y) {
	return x > y;
}
void dfs(int x) {
	if (cnt1 > n/2 || cnt2> n/2 || cnt3 > n/2) return;
	if (x == n+1) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += a[i][f[i]];
		}
		ans = max(ans, res);
		return;
	}
	f[x] = 1, cnt1++;
	dfs(x+1);
	f[x] = 2, cnt1--, cnt2++;
	dfs(x+1);
	f[x] = 3, cnt2--, cnt3++;
	dfs(x+1);
	cnt3--;
}
void work1() {
	cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
	for (int i = 1; i <= n; i++) 
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	dfs(1);
	cout << ans << endl;
}
void work2() {
	sort(x+1, x+n+1, cmp);
	int res = 0;
	for (int i = 1; i <= n/2; i++) 
		res += x[i];
	cout << res << endl;
}
void work3() {
	sort(x+1, x+n+1, cmp);
	sort(y+1, y+n+1, cmp);
	sort(z+1, z+n+1, cmp);
	int p = n, cntx = 1, cnty = 1, cntz = 1, res = 0;
	while (p--) {
		if (cntx >= cnty && cntx >= cntz) {
			if (cntx < n/2) {
				res += x[cntx];
				cntx++;
			} else {
				if (cnty >= cntz) {
					if (cnty < n/2) {
						res += y[cnty];
						cnty++;
					} else {
						res += z[cntz];
						cntz++;
					}
				}
			}
		} else if (cnty >= cntx && cnty >= cntz) {
			if (cnty < n/2) {
				res += y[cnty];
				cnty++;
			} else {
				if (cntx >= cntz) {
					if (cntx < n/2) {
						res += x[cntx];
						cntx++;
					} else {
						res += z[cntz];
						cntz++;
					}
				}
			}
		} else if (cntz >= cntx && cntz >= cnty) {
			if (cntz < n/2) {
				res += z[cntz];
				cntz++;
			} else {
				if (cntx >= cnty) {
					if (cntx < n/2) {
						res += x[cntx];
						cntx++;
					} else {
						res += y[cnty];
						cntz++;
					}
				}
			}
		}
	}
	cout << res << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n <= 10) work1();
		else {
			bool flag = 1;
			for (int i = 1; i <= n; i++) {
				cin >> x[i] >> y[i] >> z[i];
				if (y[i] != 0 || z[i] != 0) 
					flag = 0;
			}
			if (flag) work2();
			else work3();
		}
	}
	return 0;
}
