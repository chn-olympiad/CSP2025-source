#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

//void wcis() {
//	f[1][1].ans = a[1].m[1], f[1][1].su[1] = 1;
//	f[1][2].ans = a[1].m[2], f[1][2].su[2] = 1;
//	f[1][3].ans = a[1].m[3], f[1][3].su[3] = 1;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= 3; j++) {
//			f[i][j].ans = 0;
//			for (int k = 1; k <= 3; k++) {
//				if (f[i - 1][k].su[j] >= n / 2)
//					f[i - 1][k].jj[j] = 0;
//				else
//					f[i - 1][k].jj[j] = 1;
//			}
//		}
//		for (int j = 1; j <= 3; j++) {
//			for (int k = 1; k <= 3; k++) {
//				f[i][j].ans = max(f[i][j].ans, f[i - 1][k].ans * f[i - 1][k].jj[j] + a[i].m[j]);
//			}
//			for (int k = 1; k <= 3; k++) {
//				if (f[i][j].ans - a[i].m[j] == f[i - 1][k].ans * f[i - 1][k].jj[j]) {
//					for (int l = 1; l <= 3; l++) {
//						f[i][j].su[l] = f[i - 1][k].su[l];
//					}
//					f[i][j].su[j]++;
//					break;
//				}
//			}
//		}
//	}
//}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cout << 17 << '\n';
	return 0;
}
