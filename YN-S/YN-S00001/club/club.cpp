#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int maxn = 250000;
set<int>s2, s3;
ll n, t, a[4][maxn], ans = -1, b[maxn], c[maxn], maxx[maxn];
//set<int>s;
int cnt[10];

void dfs(ll tot, int id) {
//	cout << tot << " " << id << endl;
	if (id > n) {
		//cout << tot << endl;
		ans = max(tot, ans);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		//cout << tot << " " << id << " " << i << endl;
		if (cnt[i] < n / 2) {
			cnt[i]++;
			dfs(tot + a[i][id], id + 1);
			cnt[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		//s.clear();
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			s2.insert(a[2][i]);
			s3.insert(a[3][i]);
		}
		for (int i = 1; i <= 5; i++) {
			cnt[i] = 0;
		}
		if (n <= 20) {
			dfs(0, 1);
		} else if (s2.size() == 1 && s3.size() == 1) {
			for (int i = 1; i <= n; i++) {
				b[i] = a[1][i];
			}
			sort(b + 1, b + n + 1);
			for (int i = n; i > n / 2; i--) {
				ans += b[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}