#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10;

struct aa {
	int a, b, c;
	int mx;
	int id;
	int val;
} h[N];

bool cmp(aa a, aa b) {
	return a.id < b.id;
}

bool cmp2(pair<PII, int> a, pair<PII, int> b) {
	return a.se < b.se;
}

void solve() {
	int t;
	cin >> t;
	while (t --) {
		// 输入和预处理
		int n;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> h[i].a >> h[i].b >> h[i].c;
			h[i].mx = max(h[i].a, max(h[i].b, h[i].c));
			h[i].val = h[i].mx;
			if (h[i].mx == h[i].a) {
				h[i].id = 1;
			}
			if (h[i].mx == h[i].b) {
				h[i].id = 2;
			}
			if (h[i].mx == h[i].c) {
				h[i].id = 3;
			}
		}
		sort(h + 1, h + 1 + n, cmp);
//		for (int i = 1; i <= n; i ++) {
//			cout << h[i].a << ' ' << h[i].b << ' ' << h[i].c << ' ' << h[i].mx << ' ' << h[i].id << endl;
//		}
//		cout << endl;
		int x1 = 0, x2 = 0, x3 = 0;
		int r1 = 0, r2 = 0, r3 = 0;
		for (int i = 1; i <= n; i ++) {
			if (h[i].id == 1) {
				x1 ++;
				r1 = max(r1, i);
			}
			if (h[i].id == 2) {
				x2 ++;
				r2 = max(r2, i);
			}
			if (h[i].id == 3) {
				x3 ++;
				r3 = max(r3, i);
			}
		}
		// cout << x1 << ' ' << x2 << ' ' << x3 << endl;
		// cout << r1 << ' ' << r2 << ' ' << r3 << endl;

		// 换社团 1 -> 2,3
		if (x1 > n / 2) {
			int t = x1 - n / 2;
			vector<pair<PII, int>> st;
			for (int i = 1; i <= r1; i ++) {
				int x = 2, y = h[i].a - h[i].b;
				int xx = 3, yy = h[i].a - h[i].c;
				if (y < yy)
					st.push_back({{i, x}, y});
				else
					st.push_back({{i, xx}, yy});
			}
			sort(st.begin(), st.end(), cmp2);
			for (auto it : st) {
				if (t == 0)
					break;
				int i = it.fi.fi;
				int new_id = it.fi.se;
				if (new_id == 2) {
					h[i].val = h[i].b;
				}
				if (new_id == 3) {
					h[i].val = h[i].c;
				}
				t --;
				// cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << endl;
			}

			int sum = 0;
			for (int i = 1; i <= n; i ++) {
				sum += h[i].val;
			}
			cout << sum << endl;
		}

		// 换社团 2 -> 1,3
		if (x2 > n / 2) {
			int t = x2 - n / 2;
			vector<pair<PII, int>> st;
			// cout << "###" << ' ' << r1 + 1 << ' ' << r2 << endl;
			for (int i = r1 + 1; i <= r2; i ++) {
				int x = 1, y = h[i].b - h[i].a;
				int xx = 3, yy = h[i].b - h[i].c;
				if (y < yy)
					st.push_back({{i, x}, y});
				else
					st.push_back({{i, xx}, yy});
			}
			sort(st.begin(), st.end(), cmp2);
			for (auto it : st) {
				if (t == 0)
					break;
				int i = it.fi.fi;
				int new_id = it.fi.se;
				if (new_id == 1) {
					h[i].val = h[i].a;
				}
				if (new_id == 3) {
					h[i].val = h[i].c;
				}
				t --;
				// cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << endl;
			}

			int sum = 0;
			for (int i = 1; i <= n; i ++) {
				sum += h[i].val;
			}
			cout << sum << endl;
		}

		// 换社团 3 -> 1,2
		if (x3 > n / 2) {
			int t = x3 - n / 2;
			vector<pair<PII, int>> st;
			for (int i = r2 + 1; i <= r3; i ++) {
				int x = 2, y = h[i].c - h[i].b;
				int xx = 1, yy = h[i].c - h[i].a;
				if (y < yy)
					st.push_back({{i, x}, y});
				else
					st.push_back({{i, xx}, yy});
			}
			sort(st.begin(), st.end(), cmp2);
			for (auto it : st) {
				if (t == 0)
					break;
				int i = it.fi.fi;
				int new_id = it.fi.se;
				if (new_id == 2) {
					h[i].val = h[i].b;
				}
				if (new_id == 1) {
					h[i].val = h[i].a;
				}
				t --;
				// cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << endl;
			}

			int sum = 0;
			for (int i = 1; i <= n; i ++) {
				sum += h[i].val;
			}
			cout << sum << endl;
		}
		if (x1 <= n / 2 && x2 <= n / 2 && x3 <= n / 2) {
			int sum = 0;
			for (int i = 1; i <= n; i ++) {
				sum += h[i].val;
			}
			cout << sum << endl;
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-S2025!!!
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/