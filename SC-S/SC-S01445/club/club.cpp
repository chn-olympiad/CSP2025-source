#include<bits/stdc++.h>
using namespace std;
struct myd {
	int a[3];
	int dz, de;
};
const int M = 2 * 1e+4 + 5;
int aba[M];
int az = 0, bz = 0;
int bba[M];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		int n;
		cin >> n;
		vector<myd> sz;
		if (n == 2) {
			for (int i = 0; i < n; i++) {
				int a0, b0, c0;
				cin >> a0 >> b0 >> c0;
				sz.push_back({a0, b0, c0});
				if (a0 == max(a0, max(b0, c0))) {
					sz[i].dz = 0;
					if (b0 == max(b0, c0)) {
						sz[i].de = 1;
					} else {
						sz[i].de = 2;
					}
				} else  if (b0 == max(a0, max(b0, c0))) {
					sz[i].dz = 1;
					if (a0 == max(a0, c0)) {
						sz[i].de = 0;
					} else {
						sz[i].de = 2;
					}
				} else {
					sz[i].dz = 2;
					if (b0 == max(b0, a0)) {
						sz[i].de = 1;
					} else {
						sz[i].de = 0;
					}
				}
			}
			if (sz[0].dz != sz[1].dz) {
				ans = sz[0].a[sz[0].dz] + sz[1].a[sz[1].dz];
			} else {
				ans = max(sz[0].a[sz[0].de] + sz[1].a[sz[1].dz], sz[0].a[sz[0].dz] + sz[1].a[sz[1].de]);
			}
		} else {
			for (int i = 0; i < n; i++) {
				int a0, b0, c0;
				cin >> a0 >> b0 >> c0;
				sz.push_back({a0, b0, c0});
				if (c0 != 0) {
					ans += max(a0, max(b0, c0));
				} else {
					if (a0 > b0) {
						aba[a0 - b0]++;
						ans += a0;
					} else {
						aba[b0 - a0]++;
						ans += b0;
					}
				}
			}
			if (aba[1] != 0) {
				if (az > bz) {
					int gd = 0;
					while (1) {
						if (az - bz <= aba[gd] * 2) {
							ans -= gd*(az - bz) / 2;
							break;
						} else {
							ans -= gd*aba[gd];
							az -= aba[gd];
							bz += aba[gd];
						}
						gd++;
					}
				} else if (bz > az) {
					int gd = 0;
					while (1) {
						if (bz - az <= bba[gd] * 2) {
							ans -= gd*(bz - az) / 2;
							break;
						} else {
							ans -= gd*bba[gd];
							bz -= bba[gd];
							az += bba[gd];
						}
						gd++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}