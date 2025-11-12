#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int sat1[N], sat2[N], sat3[N], maxn[N];
int cnt1, cnt2, cnt3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> sat1[i] >> sat2[i] >> sat3[i];
			int max23 = max(sat2[i], sat3[i]), max123 = max(sat1[i], max23);
			maxn[i] = max123;
			ans += max123;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}