#include <bits/stdc++.h>
using namespace std;
int T, n;

struct node {
	int t1, t2, t3, minn, maxn, mid, cha1, cha2, cha3;
} a[20005];

inline bool cmp(node x, node y) {
	if (x.cha1 != y.cha1)
		return x.cha1 > y.cha1;
	else {
		if (x.cha2 != y.cha2)
			return x.cha2 > y.cha2;
		else {
			return x.cha3 > y.cha3;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].t1 >> a[i].t2 >> a[i].t3;
			if (a[i].t1 >= a[i].t2 && a[i].t2 >= a[i].t3) {
				a[i].maxn = a[i].t1;
				a[i].mid = a[i].t2 ;
				a[i].minn = a[i].t3  ;
			} else if (a[i].t1 >= a[i].t3 && a[i].t3 >= a[i].t2) {
				a[i].maxn = a[i].t1 ;
				a[i].mid = a[i].t3  ;
				a[i].minn = a[i].t2 ;
			} else if (a[i].t2 >= a[i].t1 && a[i].t1 >= a[i].t3) {
				a[i].maxn = a[i].t2;
				a[i].mid = a[i].t1  ;
				a[i].minn = a[i].t3;
			} else if (a[i].t2 >= a[i].t3 && a[i].t3 >= a[i].t1) {
				a[i].maxn = a[i].t2 ;
				a[i].mid = a[i].t3;
				a[i].minn = a[i].t1;
			} else if (a[i].t3 >= a[i].t1 && a[i].t1 >= a[i].t2) {
				a[i].maxn = a[i].t3 ;
				a[i].mid = a[i].t1;
				a[i].minn = a[i].t2 ;
			} else if (a[i].t3 >= a[i].t2 && a[i].t2 >= a[i].t1) {
				a[i].maxn = a[i].t3 ;
				a[i].mid = a[i].t2;
				a[i].minn = a[i].t1;
			}
			a[i].cha2 = a[i].maxn - a[i].minn;
			a[i].cha1 = a[i].maxn - a[i].mid;
			a[i].cha3 = a[i].minn - a[i].mid;
		}
		sort(a + 1, a + n + 1, cmp);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].maxn == a[i].t1) {
				if (cnt1 < n / 2) {
					sum += a[i].maxn;
					cnt1++;
				} else {
					if (a[i].t2 == a[i].minn) {
						if (cnt3 < n / 2) {
							sum += a[i].t3;
							cnt3++;
						} else if (cnt2 < n / 2) {
							sum += a[i].t2;
							cnt2++;
						} else {
							break;
						}
					}
					if (a[i].t3 == a[i].minn) {
						if (cnt2 < n / 2) {
							sum += a[i].t2;
							cnt2++;
						} else if (cnt3 < n / 2) {
							sum += a[i].t3;
							cnt3++;
						} else {
							break;
						}
					}
				}
			}
			if (a[i].maxn == a[i].t2) {
				if (cnt2 < n / 2) {
					sum += a[i].maxn;
					cnt2++;
				} else {
					if (a[i].t1 == a[i].minn) {
						if (cnt3 < n / 2) {
							sum += a[i].t3;
							cnt3++;
						} else if (cnt1 < n / 2) {
							sum += a[i].t1;
							cnt1++;
						} else {
							break;
						}
					}
					if (a[i].t3 == a[i].minn) {
						if (cnt1 < n / 2) {
							sum += a[i].t1;
							cnt1++;
						} else if (cnt3 < n / 2) {
							sum += a[i].t3;
							cnt3++;
						}
					}
				}
			}
			if (a[i].maxn == a[i].t3) {
				if (cnt3 < n / 2) {
					sum += a[i].maxn;
					cnt3++;
				} else {
					if (a[i].t2 == a[i].minn) {
						if (cnt1 < n / 2) {
							sum += a[i].t1;
							cnt1++;
						} else if (cnt2 < n / 2) {
							sum += a[i].t2;
							cnt2++;
						}
					}
					if (a[i].t1 == a[i].minn) {
						if (cnt2 < n / 2) {
							sum += a[i].t2;
							cnt2++;
						} else if (cnt1 < n / 2) {
							sum += a[i].t1;
							cnt1++;
						}
					}
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
