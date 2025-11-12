#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500010], x[10], y[10];
struct rr{
	int ll;
	int rr;
}f[500010];
signed main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, k, cz = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			for (int j = 1; j <= 8; j++) {
				x[j] = 0;
			}
			for (int i = l; i <= r; i++) {
				for (int j = 1; j <= 8; j++) {
					y[j] = 0;
				}
				int sum = a[i];
				if (i == l) {
					if (sum >= 128) {
						x[8] = 1;
						sum -= 128;
					}
					if (sum >= 64) {
						x[7] = 1;
						sum -= 64;
					}
					if (sum >= 32) {
						x[6] = 1;
						sum -= 32;
					}
					if (sum >= 16) {
						x[5] = 1;
						sum -= 16;
					}
					if (sum >= 8) {
						x[4] = 1;
						sum -= 8;
					}
					if (sum >= 4) {
						x[3] = 1;
						sum -= 4;
					}
					if (sum >= 2) {
						x[2] = 1;
						sum -= 2;
					}
					if (sum >= 1) {
						x[1] = 1;
						sum -= 1;
					}
				} else {
					if (sum >= 128) {
						y[8] = 1;
						sum -= 128;
					}
					if (sum >= 64) {
						y[7] = 1;
						sum -= 64;
					}
					if (sum >= 32) {
						y[6] = 1;
						sum -= 32;
					}
					if (sum >= 16) {
						y[5] = 1;
						sum -= 16;
					}
					if (sum >= 8) {
						y[4] = 1;
						sum -= 8;
					}
					if (sum >= 4) {
						y[3] = 1;
						sum -= 4;
					}
					if (sum >= 2) {
						y[2] = 1;
						sum -= 2;
					}
					if (sum >= 1) {
						y[1] = 1;
						sum -= 1;
					}
				}
				for (int j = 1; j <= 8; j++) {
					if ((x[j] == 0 && y[j] == 1) || (x[j] == 1 && y[j] == 0)) {
						x[j] = 1;
					} else {
						x[j] = 0;
					}
				}
			}
			int num = 0;
			if (x[1] == 1) {
				num += 1;
			}
			if (x[2] == 1) {
				num += 2;
			}
			if (x[3] == 1) {
				num += 4;
			}
			if (x[4] == 1) {
				num += 8;
			}
			if (x[5] == 1) {
				num += 16;
			}
			if (x[6] == 1) {
				num += 32;
			}
			if (x[7] == 1) {
				num += 64;
			}
			if (x[8] == 1) {
				num += 128;
			}
			if (num == k) {
				f[cz].ll = l;
				f[cz].rr = r;
				cz++;
			}
		}
	}
	cz--;
	for (int i = 1; i <= cz; i++) {
		for (int j = 1; j < cz; j++) {
			if (f[j].ll > f[j + 1].ll) {
				int f1 = f[j].ll, f2 = f[j].rr;
				f[j].ll = f[j + 1].ll;
				f[j].rr = f[j + 1].rr;
				f[j + 1].ll = f1;
				f[j + 1].rr = f2;
			} else if (f[j].ll == f[j + 1].ll) {
				int f1 = f[j].ll, f2 = f[j].rr;
				if (f[j].rr > f[j].rr) {
					f[j].ll = f[j + 1].ll;
					f[j].rr = f[j + 1].rr;
					f[j + 1].ll = f1;
					f[j + 1].rr = f2;
				}
			}
		}
	}
	int cc = f[1].ll;
	for (int i = 2; i <= cz; i++) {
		if (f[i].ll == cc) {
			f[i].ll = 0, f[i].rr = 0;
		} else {
			cc = f[i].ll;
		}
	}
	for (int i = 1; i <= cz; i++) {
		for (int j = 1; j < cz; j++) {
			if (f[j].rr > f[j + 1].rr) {
				int f1 = f[j].ll, f2 = f[j].rr;
				f[j].ll = f[j + 1].ll;
				f[j].rr = f[j + 1].rr;
				f[j + 1].ll = f1;
				f[j + 1].rr = f2;
			} else if (f[j].rr == f[j + 1].rr) {
				int f1 = f[j].ll, f2 = f[j].rr;
				if (f[j].ll < f[j].ll) {
					f[j].ll = f[j + 1].ll;
					f[j].rr = f[j + 1].rr;
					f[j + 1].ll = f1;
					f[j + 1].rr = f2;
				}
			}
		}
	}
	cc = f[1].rr;
	for (int i = 2; i <= cz; i++) {
		if (f[i].rr == cc) {
			f[i].ll = 0, f[i].rr = 0;
		} else {
			cc = f[i].rr;
		}
	}
	for (int i = 1; i <= cz; i++) {
		for (int j = 1; j < cz; j++) {
			if (f[j].ll > f[j + 1].ll) {
				int f1 = f[j].ll, f2 = f[j].rr;
				f[j].ll = f[j + 1].ll;
				f[j].rr = f[j + 1].rr;
				f[j + 1].ll = f1;
				f[j + 1].rr = f2;
			} else if (f[j].ll == f[j + 1].ll) {
				int f1 = f[j].ll, f2 = f[j].rr;
				if (f[j].rr > f[j].rr) {
					f[j].ll = f[j + 1].ll;
					f[j].rr = f[j + 1].rr;
					f[j + 1].ll = f1;
					f[j + 1].rr = f2;
				}
			}
		}
	}
	for (int i = 1; i < cz; i++) {
		if (f[i].rr >= f[i + 1].ll) {
			if ((f[i].rr - f[i].ll) > (f[i + 1].rr - f[i + 1].ll)) {
				f[i].ll = 0, f[i].rr = 0;
			}
		}
	}
	int re = 0;
	for (int i = 1; i <= cz; i++) {
		if (f[i].ll != 0) {
			re++;
		}
	}
	cout << re;
	return 0;
}
