#include <bits/stdc++.h>
using namespace std;

struct man {
	int fi, se, th, hism;
} m[200005];
int ton[100005][3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].fi >> m[i].se >> m[i].th;
			m[i].hism = max(m[i].fi, max(m[i].se, m[i].th));
			ans += m[i].hism;
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
