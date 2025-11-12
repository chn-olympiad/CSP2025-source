#include <bits/stdc++.h>
using namespace std;
long long ans, n, a[5050], maxa = 0, b[5050], cnt, cnt1;
map<long long, int> m;
bool f[5050];

//void dfs(int x) {
//	if (x == 0) {
//		int aa = 0, ans1 = 0;
//		sort(b + 1, b + 1 + cnt, greater<int>() );
//		for (int i = 1; i <= cnt; i++) {
//			ans1 *= 10;
//			ans1 += b[i];
//			aa += b[i];
//
//		}
//
//		if (aa > b[1] * 2 && m[ans1] == 0) {
//			cnt1++;
//			m[ans1]++;
//			cout << ans1 << ' ';
//		}
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (f[i] == false) {
//			b[x] = a[i];
//			f[i] = true;
//			dfs(x - 1);
//			f[i] = false;
//		}
//	}
//
//}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxa = max(a[i], maxa);
	}
	if (n <= 3) {
		if (a[1] + a[2] + a[3] > maxa * 2)
			cout << 1;
	}
	if (maxa == 1) {
		cout << n - 2;
	}
	return 0;
}
