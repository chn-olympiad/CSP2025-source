#include <bits/stdc++.h>
using namespace std;

pair<long long, pair<long long, long long>> ar[100010];
long long a[100010], b[100010], c[100010];

bool cmpa(int x, int y) {
	return x < y;
}
bool cmpb(int x, int y) {
	return x < y;
}
bool cmpc(int x, int y) {
	return x < y;
}

void solve() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	memset(ar, 0, sizeof ar);
	long long n;
	cin >> n;
	long long cnta = 0, cntb = 0, cntc = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].first >> ar[i].second.first >> ar[i].second.second;
		if (ar[i].first >= ar[i].second.first && ar[i].first >= ar[i].second.second) {
			ans += ar[i].first;
			a[++cnta] = ar[i].first - max(ar[i].second.second, ar[i].second.first);
		}
		else if (ar[i].second.first >= ar[i].first && ar[i].second.first >= ar[i].second.second) {
			ans += ar[i].second.first;
			b[++cntb] = ar[i].second.first - max(ar[i].second.second, ar[i].first);
		}
		else {
			ans += ar[i].second.second;
			c[++cntc] = ar[i].second.second - max(ar[i].first, ar[i].second.first);
		}
	}
	
	if (cnta > n / 2) {
		sort(a + 1, a + cnta + 1, cmpa);
		for (int i = 1; i <= cnta - n / 2; i++) {
			ans -= a[i];
		}
	}
	else if (cntb > n / 2) {
		sort(b + 1, b + cntb + 1, cmpb);
		for (int i = 1; i <= cntb - n / 2; i++) {
			ans -= b[i];
		}
	}
	else if (cntc > n / 2) {
		sort(c + 1, c + cntc + 1, cmpc);
		for (int i = 1; i <= cntc - n / 2; i++) {
			ans -= c[i];
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
