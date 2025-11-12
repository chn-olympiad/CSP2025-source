#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
using ll = long long;
int a[N + 5][3], ct[3];
priority_queue<int> q0, q1, q2;
void solv() {
	int n; cin >> n;
	ll ret = 0;
	for (int i = 1, nw; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		nw = max({a[i][0], a[i][1], a[i][2]});
		ret += nw;
		if (a[i][0] == nw) {
			++ct[0];
			q0.push(max(a[i][1], a[i][2]) - a[i][0]);
		} else if (a[i][1] == nw) {
			++ct[1];
			q1.push(max(a[i][0], a[i][2]) - a[i][1]);
		} else {
			++ct[2];
			q2.push(max(a[i][0], a[i][1]) - a[i][2]);
		}
	}
	int lm = (n >> 1);
	while (ct[0] > lm) {
		--ct[0];
		ret += q0.top(); q0.pop();
	}
	while (ct[1] > lm) {
		--ct[1];
		ret += q1.top(); q1.pop();
	}
	while (ct[2] > lm) {
		--ct[2];
		ret += q2.top(); q2.pop();
	}
	cout << ret << '\n';
	while (q0.size()) q0.pop();
	while (q1.size()) q1.pop();
	while (q2.size()) q2.pop();
	ct[0] = ct[1] = ct[2] = 0;
	for (int i = 1; i <= n; i++) {
		a[i][0] = a[i][1] = a[i][2] = 0;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--) solv();
	return 0;
}
