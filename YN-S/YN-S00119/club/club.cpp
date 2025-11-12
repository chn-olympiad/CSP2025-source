#include <bits/stdc++.h>
#define int long long
using namespace std;

struct club {
	int bh, a1, a2, a3;
} a[200500];
vector<int> c1, c1xb, c2, c2xb, c3, c3xb;
queue<int> q;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {

			a[i].bh = i;
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;

			if (a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3) {
				if (c1.size() > n / 2 - 1) {
					if (a[i].a1 > c1[0]) {
						if (upper_bound(c1.begin(), c1.end(), a[i].a1) != c1.end()) {
							c1.insert(upper_bound(c1.begin(), c1.end(), a[i].a1) - 1, a[i].a1);
							c1xb.insert(upper_bound(c1.begin(), c1.end(), a[i].a1) - 1, a[i].bh);
						} else {
							c1.push_back(a[i].a1);
							c1xb.push_back(a[i].bh);
						}
						q.push(c1xb[0]);
						c1.erase(c1.begin());
						c1xb.erase(c1xb.begin());
					} else
						q.push(a[i].bh);
				} else {
					c1.push_back(a[i].a1);
					c1xb.push_back(a[i].bh);
				}
			} else if (a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3) {
				if (c2.size() > n / 2 - 1) {
					if (a[i].a2 > c2[0]) {
						if (upper_bound(c2.begin(), c2.end(), a[i].a2) != c2.end()) {
							c2.insert(upper_bound(c2.begin(), c2.end(), a[i].a2) - 1, a[i].a2);
							c2xb.insert(upper_bound(c2.begin(), c2.end(), a[i].a2) - 1, a[i].bh);
						} else {
							c2.push_back(a[i].a2);
							c2xb.push_back(a[i].bh);
						}
						q.push(c2xb[0]);
						c2.erase(c2.begin());
						c2xb.erase(c2xb.begin());
					} else
						q.push(a[i].bh);
				} else {
					c2.push_back(a[i].a2);
					c2xb.push_back(a[i].bh);
				}
			} else {
				if (c3.size() > n / 2 - 1) {
					if (a[i].a3 > c3[0]) {
						if (upper_bound(c3.begin(), c3.end(), a[i].a3) != c3.end()) {
							c3.insert(upper_bound(c3.begin(), c3.end(), a[i].a3) - 1, a[i].a3);
							c3xb.insert(upper_bound(c3.begin(), c3.end(), a[i].a3) - 1, a[i].bh);
						} else {
							c3.push_back(a[i].a3);
							c3xb.push_back(a[i].bh);
						}
						q.push(c3xb[0]);
						c3.erase(c3.begin());
						c3xb.erase(c3xb.begin());
					} else
						q.push(a[i].bh);
				} else {
					c3.push_back(a[i].a3);
					c3xb.push_back(a[i].bh);
				}
			}

		}
		int cnt = 0;
		while (q.size() > 0) {
			int tmp = q.front();
			q.pop();
			if (a[tmp].a1 > a[tmp].a2 && a[tmp].a1 > a[tmp].a3 && c1.size() > 0 &&
			        (a[c1xb[0]].a2 + a[tmp].a1 > c1[0] + a[tmp].a2
			         || a[c1xb[0]].a3 + a[tmp].a1 > c1[0] + a[tmp].a3)) {
				q.push(c1xb[0]);
				c1[0] = a[tmp].a1;
				a[c1xb[0]].a1 = 0;
				c1xb[0] = tmp;
			} else if (a[tmp].a2 > a[tmp].a1 && a[tmp].a2 > a[tmp].a3 && c2.size() > 0 &&
			           (a[c2xb[0]].a1 + a[tmp].a2 > c2[0] + a[tmp].a1
			            || a[c2xb[0]].a3 + a[tmp].a2 > c2[0] + a[tmp].a3)) {
				q.push(c2xb[0]);
				c2[0] = a[tmp].a2;
				a[c2xb[0]].a2 = 0;
				c2xb[0] = tmp;
				cnt++;
			} else if (a[tmp].a3 > a[tmp].a1 && a[tmp].a3 > a[tmp].a2 && c3.size() > 0 &&
			           (a[c3xb[0]].a1 + a[tmp].a3 > c3[0] + a[tmp].a1
			            || a[c3xb[0]].a2 + a[tmp].a3 > c3[0] + a[tmp].a2)) {

				q.push(c3xb[0]);
				c3[0] = a[tmp].a3;
				a[c3xb[0]].a3 = 0;
				c3xb[0] = tmp;
			} else if (c1.size() >= n / 2 && c2.size() >= n / 2 ||
			           c3.size() < n / 2 && a[tmp].a3 > a[tmp].a2 && a[tmp].a3 > a[tmp].a1)
				ans += a[tmp].a3;
			else if (c1.size() >= n / 2 && c3.size() >= n / 2 ||
			         c2.size() < n / 2 && a[tmp].a2 > a[tmp].a1 && a[tmp].a2 > a[tmp].a3)
				ans += a[tmp].a2;
			else if (c2.size() >= n / 2 && c3.size() >= n / 2 ||
			         c1.size() < n / 2 && a[tmp].a1 > a[tmp].a2 && a[tmp].a1 > a[tmp].a3)
				ans += a[tmp].a1;

		}
		for (int i = 0; i < c1.size(); i++)
			ans += c1[i];
		for (int i = 0; i < c2.size(); i++)
			ans += c2[i];
		for (int i = 0; i < c3.size(); i++)
			ans += c3[i];
		cout << ans << "\n";
		c1.clear();
		c1xb.clear();
		c2.clear();
		c2xb.clear();
		c3.clear();
		c3xb.clear();
	}


	return 0;
}
//Ren5Jie4Di4Ling5%
/*

*/