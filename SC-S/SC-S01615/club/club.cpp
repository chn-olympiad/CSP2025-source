#include<bits/stdc++.h>
using namespace std;
long long t, n, a1[100010], a2[1000010], a3[100010], flag1 = 1, ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			if (a2[i] != 0 || a3[i] != 0) flag1 = 0;
		}
		if (flag1) {
			sort(a1 + 1, a1 + n + 1, greater<long long>());
			for (int i = 1; i <= n / 2; i++) ans += a1[i];
			cout << ans << endl;
		}
	}
	return 0;
}