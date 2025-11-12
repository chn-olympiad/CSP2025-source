#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, d[maxn], ans;
vector <int> vec[5];
struct node {int v, id;}a[maxn][5];
void solve() {
	cin >> n; m = n >> 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j].v;
			a[i][j].id = j;
		}
		sort(a[i] + 1, a[i] + 4, [&](node x, node y) {
			return x.v > y.v;
		});
		d[i] = a[i][1].v - a[i][2].v;
	}
	for(int i = 1; i <= 3; i++) vec[i].clear();
	for(int i = 1; i <= n; i++) vec[a[i][1].id].push_back(i);
	int p = 0;
	for(int i = 1; i <= 3; i++) {
		if(vec[i].size() > n / 2) p = i;
	}
	ans = 0;
	if(!p) {
		for(int i = 1; i <= 3; i++) {
			for(int x : vec[i]) {
				ans += a[x][1].v;
			}
		}
		cout << ans << "\n";
		return;
	}
	sort(vec[p].begin(), vec[p].end(), [&](int x, int y) {
		return d[x] > d[y];
	});
	for(int i = 0; i < n / 2; i++) {
		ans += a[vec[p][i]][1].v;
	}
	for(int i = n / 2; i < vec[p].size(); i++) {
		ans += a[vec[p][i]][2].v;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i][1].id != p) ans += a[i][1].v;
	}
	cout << ans << "\n";
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
