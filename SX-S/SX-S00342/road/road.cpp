#include <bits/stdc++.h>
using namespace std;
long long n, m, mins = 100000000, k, l[1005], r[1005];
long long mp[1005][1005];

struct zzz {
	long long up;
	long long s[1005];
} a[15];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		long long sum;
		cin >> l[i] >> r[i];
		cin >> sum;
		mp[l[i]][r[i]] = sum;
		mp[r[i]][l[i]] = sum;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i].up;
		long long ans = a[i].up;
		for (int j = 1; j <= n; j++) {
			cin >> a[i].s[j];
			ans += a[i].s[j];
		}
		mins = min(mins, ans);

	}
	cout << mins;
	return 0;
}
