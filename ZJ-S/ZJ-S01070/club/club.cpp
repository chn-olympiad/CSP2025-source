#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#include <set>
using namespace std;
int getSpecial(vector<int*> &a) {
	bool flag1 = true, flag2 = true;
	for (auto data : a) {
		if (data[1] != 0 || data[2] != 0) {
			flag1 = false;
		}
		if (data[2] != 0) {
			flag2 = false; 
		}
	}
	if (flag1) {
		return 1;
	}
	if (flag2) {
		return 2;
	}
	return 0;
}
struct {
	int c0 = 0, c1 = 0, c2 = 0;
	int maxn;
	int ans = 0;
	int sum = 0;
} di;
void dfs(vector<int*> &a, int p) {
	if (p > (di.maxn << 1)) {
		di.ans = max(di.ans, di.sum);
		return;
	}
	if (di.c0 < di.maxn) {
		di.c0 += 1;
		di.sum += a[p][0];
		dfs(a, p + 1);
		di.c0 -= 1;
		di.sum -= a[p][0];
	}
	if (di.c1 < di.maxn) {
		di.c1 += 1;
		di.sum += a[p][1];
		dfs(a, p + 1);
		di.c1 -= 1;
		di.sum -= a[p][1];
	}
	if (di.c2 < di.maxn) {
		di.c2 += 1;
		di.sum += a[p][2];
		dfs(a, p + 1);
		di.c2 -= 1;
		di.sum -= a[p][2];
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int*> a(n + 1);
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		a[i][3] = i;
	}
	int doing = getSpecial(a);
	if (!doing && n <= 30) {
		// n <= 30时 暴力
		di.maxn = n >> 1;
		dfs(a, 1);
		cout << di.sum << endl;
	} else {
		if (doing == 1) {
			// 特殊性质A
			sort(a.begin() + 1, a.end(), [](int *x, int *y) -> bool {
				return x[0] > y[0];
			});
			int num = n >> 1;
			int sum = 0;
			for (int i = 1; i <= num; i += 1) {
				sum += a[i][0];
			}
			cout << sum << endl;
		} else {
			// 特殊性质B
//			vector<int[4]> b = a;
//			sort(a.being() + 1, a.end(), [](int *x, int *y) -> bool {
//				return x[0] > y[0];
//			});
//			sort(b.begin() + 1, b.end(), [](int *x, int *y) -> bool {
//				return x[1] > y[1];
//			})
//			for (int i = 1; i <= n; i += 1) {
//				a[i][2] = a[i][1] - a[i][0];
//				b[i][2] = b[i][0] - b[i][1];
//			}
//			set<int> alib, blib;
//			int need = n >> 1;
//			int aptr = need + 1, bptr = need + 1;
//			int asum = 0, bsum = 0;
//			for (int i = 1; i >= need; i += 1) {
//				alib.insert(a[i][3]);
//				asum += a[i][0];
//				blib.insert(b[i][3]);
//				bsum += b[i][1];
//			}
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
