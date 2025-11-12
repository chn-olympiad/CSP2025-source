#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][10], q1[N], q2[N], q3[N];
int n;
inline bool cmp(int a, int b) {
	return a > b;
}
inline void solve() {
	scanf("%d", &n);
	int tot1 = 0, tot2 = 0, tot3 = 0;
	int cnt12 = 0, cnt13 = 0, cnt23 = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		int t1 = a[i][1], t2 = a[i][2], t3 = a[i][3];
		if (t1 > t2 && t2 >= t3) {
			tot1++;
			a[i][4] = t1 - t2;
			q1[tot1] = a[i][4];
			ans += t1;
		}
		else if (t1 > t3 && t3 >= t2) {
			tot1++;
			a[i][4] = t1 - t3;
			q1[tot1] = a[i][4];
			ans += t1;
		}
		else if (t2 > t3 && t3 >= t1) {
			tot2++;
			a[i][4] = t2 - t3;
			q2[tot2] = a[i][4];
			ans += t2;
		}
		else if (t2 > t1 && t1 >= t3) {
			tot2++;
			a[i][4] = t2 - t1;
			q2[tot2] = a[i][4];
			ans += t2;
		}
		else if (t3 > t2 && t2 >= t1) {
			tot3++;
			a[i][4] = t3 - t2;
			q3[tot3] = a[i][4];
			ans += t3;
		}
		else if (t3 > t1 && t1 >= t2) {
			tot3++;
			a[i][4] = t3 - t1;
			q3[tot3] = a[i][4];
			ans += t3;
		}
		else if (t1 == t2) {
			cnt12++;
			ans += t1;
		}
		else if (t2 == t3) {
			cnt23++;
			ans += t2;
		}
		else if (t1 == t3) {
			cnt13++;
			ans += t3;
		}
//		cout << ans << "\n";
	}
//	cout << tot1 << " " << tot2 << " " << tot3 << "\n";
	if (tot1 > n / 2) {
//		cout << 1 << "\n";
		sort(q1 + 1, q1 + tot1 + 1, cmp);
		for (; tot1 > n / 2; tot1--) {
			ans -= q1[tot1];
		}
	}
	else if (tot2 > n / 2) {
		sort(q2 + 1, q2 + tot2 + 1, cmp);
		for (; tot2 > n / 2; tot2--) {
			ans -= q2[tot2];
		}
	}
	else if (tot3 > n / 2) {
		sort(q3 + 1, q3 + tot3 + 1, cmp);
		for (; tot3 > n / 2; tot3--) {
			ans -= q3[tot3];
		}
	}
	printf("%d\n", ans);
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
