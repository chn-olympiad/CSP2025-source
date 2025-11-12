#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, cnt[3], sum;
struct node {
	struct data {
		int number, id;
	} num[3];
	int tot;
} a[N];
bool cmp(node x, node y) {
	if (x.num[0].number != y.num[0].number)
		return x.num[0].number > y.num[0].number;
	if (x.num[1].number != y.num[1].number)
		return x.num[1].number > y.num[1].number;
	if (x.num[2].number != y.num[2].number)
		return x.num[2].number > y.num[2].number;
	return x.tot > y.tot;
}
void dfs(int k, int res) {
	if (k > n) {
		sum = max(sum, res);
		return;
	}
	for (int i = 0; i < 3; i++)
		if (cnt[a[k].num[i].id] < (n >> 1))
			cnt[a[k].num[i].id]++, dfs(k + 1, res + a[k].num[i].number), cnt[a[k].num[i].id]--;
}
void solve() {
	cin >> n;
	sum = cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i].num[j].number;
			a[i].num[j].id = j;
			if (a[i].num[j].number == 0)
				a[i].tot++;
		}
		if (a[i].num[0].number < a[i].num[1].number)
			swap(a[i].num[0], a[i].num[1]);
		if (a[i].num[1].number < a[i].num[2].number)
			swap(a[i].num[1], a[i].num[2]);
		if (a[i].num[0].number < a[i].num[1].number)
			swap(a[i].num[0], a[i].num[1]);
	}
	if (n > 10) {
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				if (cnt[a[i].num[j].id] < (n >> 1)) {
					cnt[a[i].num[j].id]++, sum += a[i].num[j].number;
					break;
				}
	} else
		dfs(1, 0);
	cout << sum << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}