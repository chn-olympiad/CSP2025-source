#include <bits/stdc++.h>
using namespace std;
struct IO {
	IO() {
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
	}
	~IO() {
		fclose(stdin);
		fclose(stdout);
	}
};
IO io;
typedef long long ll;
#define pb emplace_back
const int N = 1e5 + 10;
int n;
int a[N][3], b[N];
vector<int> vec[3];
void Solve() {
	scanf("%d", &n);
	for (int i : { 0, 1, 2 }) vec[i].clear();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j : { 0, 1, 2 }) scanf("%d", &a[i][j]);
		int p = 0;
		if (a[i][1] > a[i][p]) p = 1;
		if (a[i][2] > a[i][p]) p = 2;
		vec[p].pb(i);
		ans += a[i][p];
	}
	int p = -1, c = n / 2;
	for (int i : { 0, 1, 2 })
		if ((int)vec[i].size() > c)
			p = i;
	if (p == -1) {
		printf("%lld\n", ans);
		return;
	}
	int cnt = 0;
	for (int i : vec[p]) {
		sort(a[i], a[i] + 3);
		b[++cnt] = a[i][2] - a[i][1];
	}
	sort(b + 1, b + cnt + 1);
	for (int i = 1; i <= (int)vec[p].size() - c; i++)
		ans -= b[i];
	printf("%lld\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) Solve();
	return 0;
}