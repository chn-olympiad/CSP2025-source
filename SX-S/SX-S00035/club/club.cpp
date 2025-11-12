#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;
const int N = 1e5+5;
int n, a[N][4], t[N], cnt[5], qwq, tot, b[N];
ll sum;

void solve() {
	cin >> n, cnt[1] = cnt[2] = cnt[3] = qwq = tot = sum = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	for (int i = 1; i <= n; i++) {
		if (a[i][1] > a[i][2] && a[i][1] > a[i][3])
			t[i] = 1;
		else if (a[i][2] > a[i][3])
			t[i] = 2;
		else
			t[i] = 3;
		cnt[t[i]]++;
		sum += a[i][t[i]];
	}
	for (int i = 1; i <= 3; i++)
		if (cnt[i] > n / 2)
			qwq = i;
	if (qwq == 0) {
		cout << sum << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (t[i] != qwq)
			continue;
		int mi = 1e9;
		for (int j = 1; j <= 3; j++) {
			if (t[i] == j)
				continue;
			mi = min(mi, a[i][qwq] - a[i][j]);
		}
		b[++tot] = mi;
	}
	sort(b + 1, b + 1 + tot);
	for (int i = 1; i <= tot - n / 2; i++)
		sum -= b[i];
	cout << sum << endl;
}

signed main() {
	File("club");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}
/*
fc /W test.out test.ans
*/
