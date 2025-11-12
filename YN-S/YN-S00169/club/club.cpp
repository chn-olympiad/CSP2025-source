#include <bits/stdc++.h>
using namespace std;

struct dx {
	int bm, m;
};
int t, n, a[100010], b[100010], c[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	for (int f = 1; f <= t; f++) {
		int my = 0, ar = 0, br = 0, cr = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		bool b0 = 1, c0 = 1;
		for (int i = 1; i <= n; i++) {
			if (b[i] != 0)
				b0 = 0;
			if (c[i] != 0)
				c0 = 0;
		}
		if (b0 && c0) {
			sort(a + 1, a + n + 1);
			for (int i = n; i > n / 2; i--) {
				my += a[i];
			}
		} else {
			dx x[100010] = {}, y[100010] = {}, z[100010] = {};
			for (int i = 1; i <= n; i++) {
				if (a[i] > b[i] > c[i]) {
					x[i].m = a[i], y[i].m = b[i], z[i].m = c[i], x[i].bm = 1, y[i].bm = 2, z[i].bm = 3;
				} else if (a[i] > c[i] > b[i]) {
					x[i].m = a[i], y[i].m = c[i], z[i].m = b[i], x[i].bm = 1, y[i].bm = 3, z[i].bm = 2;
				} else if (b[i] > a[i] > c[i]) {
					x[i].m = b[i], y[i].m = a[i], z[i].m = c[i], x[i].bm = 2, y[i].bm = 1, z[i].bm = 3;
				} else if (b[i] > c[i] > a[i]) {
					x[i].m = b[i], y[i].m = c[i], z[i].m = a[i], x[i].bm = 2, y[i].bm = 3, z[i].bm = 1;
				} else if (c[i] > a[i] > b[i]) {
					x[i].m = c[i], y[i].m = a[i], z[i].m = b[i], x[i].bm = 3, y[i].bm = 1, z[i].bm = 2;
				} else if (c[i] > b[i] > a[i]) {
					x[i].m = c[i], y[i].m = b[i], z[i].m = a[i], x[i].bm = 3, y[i].bm = 2, z[i].bm = 1;
				}
			}

			for (int i = 1; i <= n; i++) {
				my += x[i].m;
			}
			//		for(int i=1;i<=n;i++){
			//			if(x[i].bm==1)ar++;
			//			else if(x[i].bm==2)br++;
			//			else if(x[i].bm==3)cr++;
			//		}
			//		if(ar>n/2||br>n/2||c>n/2){
			//			if(ar>n/2){
			//
			//			}
			//		}
		}
		cout << my << "\n";
	}
	return 0;
}