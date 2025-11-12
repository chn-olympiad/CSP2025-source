#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0;
int mg[5010], pd[5010];

void pz(int sl, int s, int zd, int zs, int a) {
	if (s == sl + 1) {
		if (zd * 2 < zs) {
			ans++;
		}
		return ;
	}
	for (int i = a + 1; i <= n; i++) {
		if (pd[i] == 0) {
			pd[i] = 1;
			int zd1 = zd;
			zd = max(zd, mg[i]);
			zs += mg[i];
			pz(sl, s + 1, zd, zs, i);
			pd[i] = 0;
			zs -= mg[i];
			zd = zd1;
		}
	}
}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	bool d = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> mg[i];
		if (mg[i] != 1)
			d = 0;
	}
	//sort(mg+1,mg+1+n);
	if (d == 1) {
		int e = 0;
		for (int i = 1; i <= n - 2; i++) {
			e += i;
		}
		cout << e;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
//		for (int i = 0; i <= 5009; i++) {
//			pd[i] = 0;
//		}
		pz(i, 1, -1, 0, 0);

	}
	cout << ans % 998244353;
	return 0;
}
