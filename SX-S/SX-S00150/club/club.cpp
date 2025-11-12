#include <bits/stdc++.h>
using namespace std;

int T;
int n, ans;

struct abc {
	int a1;
	int b1;
	int c1;
} a[100010];
int v[100010];

bool cmpA(abc x, abc y) {
	return x.b1 >= y.b1;
}

bool cmpB1(abc x, abc y) {
	if (x.a1 == y.a1) {
		return x.b1 >= y.b1;
	}
	return x.a1 > y.a1;
}

bool cmpB2(abc x, abc y) {
	if (x.b1 == y.b1) {
		return x.a1 >= y.a1;
	}
	return x.b1 > y.b1;
}

bool cmpC1(abc x, abc y) {
	return x.a1 > y.a1;
}

bool cmpC2(abc x, abc y) {
	return x.b1 > y.b1;
}

bool cmpC3(abc x, abc y) {
	return x.c1 > y.c1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		int f = 1, f1 = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].b1 >> a[i].c1;
			v[i] = 0;
			if (a[i].a1 != 0 || a[i].c1 != 0) {
				f = 0;
			}
			if (a[i].c1 != 0) {
				f1 = 0;
			}
		}
		if (f == 1) {
			sort(a + 1, a + n + 1, cmpA);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].b1;
			}
			cout << ans << endl;
		}
		//
		else if (f1 == 1) {
			int anss1 = 0, anss2 = 0;
			sort(a + 1, a + n + 1, cmpB1);
			for (int i = 1; i <= n / 2; i++) {
				anss1 += a[i].a1;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				anss1 += a[i].b1;
			}
			sort(a + 1, a + n + 1, cmpB2);
			for (int i = 1; i <= n / 2; i++) {
				anss2 += a[i].b1;
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				anss2 += a[i].a1;
			}
			cout << max(anss1, anss2) << endl;
		}
		//
		else {

			int ansC[6];
			for (int i = 0; i < 6; i++) {
				ansC[i] = -1;
			}
			//cout << 1;
			sort(a + 1, a + n + 1, cmpC1);
			for (int i = 1; i <= n / 2; i++) { //ABC
				for (int j = i + 1; j <= i + n / 2; j++) {
					int ma_zs = 0;
					sort(a + 1, a + i, cmpC1);
					for (int z = 1; z <= i; z++) {

						ma_zs += a[z].a1;
					}
					sort(a + i + 1, a + j, cmpC2);

					for (int z = i + 1; z <= j; z++) {
						ma_zs += a[z].b1;
					}
					sort(a + j + 1, a + n + 1, cmpC3);
					for (int z = j + 1; z <= n; z++) {
						ma_zs += a[z].c1;
					}
					ansC[0] = max(ansC[0], ma_zs);
				}
			}
			sort(a + 1, a + n + 1, cmpC1);
			for (int i = 1; i <= n / 2; i++) { //ACB
				//cout << 1;
				for (int j = i + 1; j <= i + n / 2; j++) {
					int ma_zs = 0;
					sort(a + 1, a + i, cmpC1);
					for (int z = 1; z <= i; z++) {
						ma_zs += a[z].a1;
					}
					sort(a + i + 1, a + j, cmpC3);
					for (int z = i + 1; z <= j; z++) {
						ma_zs += a[z].c1;
					}
					sort(a + j + 1, a + n + 1, cmpC2);
					for (int z = j + 1; z <= n; z++) {
						ma_zs += a[z].b1;
					}
					ansC[1] = max(ansC[1], ma_zs);
				}
			}
			sort(a + 1, a + n + 1, cmpC2);
			for (int i = 1; i <= n / 2; i++) { //BAC
				for (int j = i + 1; j <= i + n / 2; j++) {
					int ma_zs = 0;
					sort(a + 1, a + i, cmpC2);
					for (int z = 1; z <= i; z++) {
						ma_zs += a[z].b1;
					}
					sort(a + i + 1, a + j, cmpC1);
					for (int z = i + 1; z <= j; z++) {
						ma_zs += a[z].a1;
					}
					sort(a + j + 1, a + n + 1, cmpC3);
					for (int z = j + 1; z <= n; z++) {
						ma_zs += a[z].c1;
					}
					ansC[2] = max(ansC[2], ma_zs);
				}
			}
			sort(a + 1, a + n + 1, cmpC2);
			for (int i = 1; i <= n / 2; i++) { //BCA
				for (int j = i + 1; j <= i + n / 2; j++) {
					int ma_zs = 0;
					sort(a + 1, a + i, cmpC2);
					for (int z = 1; z <= i; z++) {
						ma_zs += a[z].b1;
					}
					sort(a + i + 1, a + j, cmpC3);
					for (int z = i + 1; z <= j; z++) {
						ma_zs += a[z].c1;
					}
					sort(a + j + 1, a + n + 1, cmpC1);
					for (int z = j + 1; z <= n; z++) {
						ma_zs += a[z].a1;
					}
					ansC[3] = max(ansC[3], ma_zs);
				}
			}
			sort(a + 1, a + n + 1, cmpC3);
			for (int i = 1; i <= n / 2; i++) { //CAB
				for (int j = i + 1; j <= i + n / 2; j++) {
					int ma_zs = 0;
					sort(a + 1, a + i, cmpC3);
					for (int z = 1; z <= i; z++) {
						ma_zs += a[z].c1;
					}
					sort(a + i + 1, a + j, cmpC1);
					for (int z = i + 1; z <= j; z++) {
						ma_zs += a[z].a1;
					}
					sort(a + j + 1, a + n + 1, cmpC2);
					for (int z = j + 1; z <= n; z++) {
						ma_zs += a[z].b1;
					}
					ansC[4] = max(ansC[4], ma_zs);
				}
			}
			sort(a + 1, a + n + 1, cmpC3);
			for (int i = 1; i <= n / 2; i++) { //CBA
				for (int j = i + 1; j <= i + n / 2; j++) {
					int ma_zs = 0;
					sort(a + 1, a + i, cmpC3);
					for (int z = 1; z <= i; z++) {
						ma_zs += a[z].c1;
					}
					sort(a + i + 1, a + j, cmpC2);
					for (int z = i + 1; z <= j; z++) {
						ma_zs += a[z].b1;
					}
					sort(a + j + 1, a + n + 1, cmpC1);
					for (int z = j + 1; z <= n; z++) {
						ma_zs += a[z].a1;
					}
					ansC[5] = max(ansC[5], ma_zs);
				}
			}
			sort(ansC, ansC + 6);
			cout << ansC[5] << endl;
		}
	}
	return 0;
}
