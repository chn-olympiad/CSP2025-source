#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int cnt[5], n, ans;

struct node {
	int x, y, z;
} a[MAXN];

bool cmp(node i, node j) {
	pair<int, int> val1[3] = {make_pair(i.x, 1), make_pair(i.y, 2), make_pair(i.z, 3)};
	pair<int, int> val2[3] = {make_pair(j.x, 1), make_pair(j.y, 2), make_pair(j.z, 3)};
	sort(val1, val1 + 3), sort(val2, val2 + 3);
	return val1[2].first + val2[1].first > val2[2].first + val1[1].first;
}

void solve() {
	ans = 0;
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int x = a[i].x, y = a[i].y, z = a[i].z;
		pair<int, int> val[3] = {make_pair(x, 1), make_pair(y, 2), make_pair(z, 3)};
		sort(val, val + 3);
		if (cnt[val[2].second] < n / 2)
			ans += val[2].first, cnt[val[2].second]++;
		else
			ans += val[1].first, cnt[val[1].second]++;
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}