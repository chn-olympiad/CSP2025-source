#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, cl[5], ls[5], ls1[5];

struct st {
	vector<pair<int, int> >a1;
} a[N];

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second > y.second;
}

bool cmp1(st x, st y) {
	return x.a1[0].second > y.a1[0].second;
}

bool cmp2(st x, st y) {
	if (x.a1[0].second - x.a1[1].second == y.a1[0].second - y.a1[1].second) {
		return (x.a1[1].second - x.a1[2].second) > (y.a1[1].second - y.a1[2].second);
	} else {
		return (x.a1[0].second - x.a1[1].second) > (y.a1[0].second - y.a1[1].second);
	}
}

void solve() {
	cin >> n;
	int a20 = 0, a30 = 0;
	if (n == 2) {
		int ma = 0;
		cin >> ls[1] >> ls[2] >> ls[3] >> ls1[1] >> ls1[2] >> ls1[3];
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3 && j != i; j++) {
				ma = max(ma, ls[i] + ls1[j]);
			}
		}
		cout << ma << endl;
		return ;
	}
	memset(cl, 0, sizeof(cl));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i].a1.clear();
	}
	for (int i = 1; i <= n; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		a[i].a1.push_back({1, q});
		a[i].a1.push_back({2, w});
		a[i].a1.push_back({3, e});
		if (w == 0) {
			a20++;
		}
		if (e == 0) {
			a30++;
		}
	}
	if (a20 == n && a30 == n) {
		int ans1 = 0;
		sort(a + 1, a + 1 + n, cmp1);
		for (int i = 1; i <= n / 2; i++) {
			ans1 += a[i].a1[0].second;
		}
		cout << ans1 << endl;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].a1.begin(), a[i].a1.end(), cmp);
	}
	sort(a + 1, a + 1 + n, cmp2);
	//sort(a + 1, a + 1 + n, cmp1);
	for (int i = 1; i <= n; i++) {
		if (cl[a[i].a1[0].first] + 1 <= n / 2) {
			cl[a[i].a1[0].first]++;
			ans += a[i].a1[0].second;
		} else if (cl[a[i].a1[1].first] + 1 <= n / 2) {
			cl[a[i].a1[1].first]++;
			ans += a[i].a1[1].second;
		} else if (cl[a[i].a1[2].first] + 1 <= n / 2) {
			cl[a[i].a1[2].first]++;
			ans += a[i].a1[2].second;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}//样例居然都过了(^.^)