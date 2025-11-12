#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pt pair <int, int>
using namespace std;
const int N = 2e5 + 10;
struct st {
	int a, b, c;
} e[N];
vector <int> p, q, r;
int temp[N];
void solve() {
	p.clear(), q.clear(), r.clear();
	int n, maxn, ans = 0;
	cin >> n;
	maxn = n / 2;
	for(int i = 1; i <= n; i++) {
		cin >> e[i].a >> e[i].b >> e[i].c;
//		ans += e[i].a + e[i].b + e[i].c;
		if(e[i].a >= e[i].b && e[i].a >= e[i].c) p.push_back(i), ans += e[i].a;
		else if(e[i].b >= e[i].c && e[i].b >= e[i].a) q.push_back(i), ans += e[i].b;
		else if(e[i].c >= e[i].a && e[i].c >= e[i].b) r.push_back(i), ans += e[i].c;
	}
	if(p.size() > maxn) {
		for(int i = 0; i < p.size(); i++) {
			if(e[p[i]].b >= e[p[i]].c) {
				temp[i] = e[p[i]].a - e[p[i]].b;
			} else {
				temp[i] = e[p[i]].a - e[p[i]].c;
			}
		}
		sort(temp, temp + p.size());
		for(int i = 0; i < p.size() - maxn; i++) {
			ans -= temp[i];
		}
	} else if(q.size() > maxn) {
		for(int i = 0; i < q.size(); i++) {
			if(e[q[i]].a >= e[q[i]].c) {
				temp[i] = e[q[i]].b - e[q[i]].a;
			} else {
				temp[i] = e[q[i]].b - e[q[i]].c;
			}
		}
		sort(temp, temp + q.size());
		for(int i = 0; i < q.size() - maxn; i++) {
			ans -= temp[i];
		}
	} else if(r.size() > maxn) {
		for(int i = 0; i < r.size(); i++) {
			if(e[r[i]].b >= e[r[i]].a) {
				temp[i] = e[r[i]].c - e[r[i]].b;
			} else {
				temp[i] = e[r[i]].c - e[r[i]].a;
			}
		}
		sort(temp, temp + r.size());
		for(int i = 0; i < r.size() - maxn; i++) {
			ans -= temp[i];
		}
	}
	cout << ans << endl;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

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
