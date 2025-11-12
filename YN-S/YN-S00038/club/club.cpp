#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct node {
	int a1, a2, a3;
	bool f = 0;
} a[N];
int n;
map<int, node>mp;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		vector<int>v1, v2, v3;
		int ans = 0;
		priority_queue<pair<int, int>>q1, q2, q3;
		int d1 = 0, d2 = 0, d3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			mp[i] = {a[i].a1, a[i].a2, a[i].a3, 0};
			tmp = max(a[i].a1, max(a[i].a2, a[i].a3));
			q1.push({a[i].a1, i});
		}
		ans = q1.top().first;
		cout << ans << '\n';
	}
	return 0;
}
