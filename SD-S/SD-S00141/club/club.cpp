#include <bits/stdc++.h>

using namespace std;

#define ll long long 

const int N = 1e5 + 5;

ll T, n, m, a[N], b[N], c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T --) {
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; i ++) cin >> a[i] >> b[i] >> c[i];
		priority_queue<int, vector<int>, greater<int> > q1, q2, q3;
		for (int i = 1; i <= n; i ++) {
			if (a[i] >= b[i] && a[i] >= c[i]) {
				if (q1.size() < n / 2) {
					q1.push(a[i] - max(b[i], c[i]));
					ans += a[i];
				}
				else {
					if (a[i] - max(b[i], c[i]) < q1.top()) {
						ans += max(b[i], c[i]);
					}
					else {
						ans -= q1.top();
						q1.pop();
						q1.push(a[i] - max(b[i], c[i]));
						ans += a[i]; 
					}
				}
			}
			else if (b[i] >= a[i] && b[i] >= c[i]) {
				if (q2.size() < n / 2) {
					q2.push(b[i] - max(a[i], c[i]));
					ans += b[i];
				}
				else {
					if (b[i] - max(a[i], c[i]) < q2.top()) {
						ans += max(a[i], c[i]);
					}
					else {
						ans += b[i];
						ans -= q2.top();
						q2.pop();
						q2.push(b[i] - max(a[i], c[i]));
					}
				}
			}
			else if (c[i] >= a[i] && c[i] >= b[i]) {
				if (q3.size() < n / 2) {
					q3.push(c[i] - max(a[i], b[i]));
					ans += c[i];
				}
				else {
					if (c[i] - max(a[i], b[i]) < q3.top()) {
						ans += max(a[i], b[i]);
					}
					else {
						ans += c[i];
						ans -= q3.top();
						q3.pop();
						q3.push(c[i] - max(a[i], b[i]));
					}
				}
			}
		}
		cout << ans << '\n';
	}
}

