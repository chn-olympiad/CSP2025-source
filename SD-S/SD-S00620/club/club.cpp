#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, l, r) for (int i = (int)(r); i >= (int)(l); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
using i64 = long long;
#define int i64
const int maxn = 1000050, mod = 998244353;
int c[5];
int a[maxn][4];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("A.txt", "r", stdi.n);
freopen("club.in", "r", stdin);
freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		rep(i, 1, n) {
			rep(j, 1, 3) {
				cin >> a[i][j];
			}
		}
		priority_queue<pair<int, pair<int, int>>> q;
		memset(c, 0, sizeof c);
		int ans = 0;
		rep(i, 1, n) {
			int id = 1, sid = 0;
			rep(j, 2, 3) {
				if (a[i][id] < a[i][j]) {
					sid = id;
					id = j;
				} else if (a[i][sid] < a[i][j]) {
					sid = j;
				}
			}
//			cout << id << " " << sid << "\n";
			q.push({a[i][sid] - a[i][id], {id, sid}});
			ans += a[i][id], c[id]++;
			if (c[id] > n / 2) {
				while (q.size() && q.top().second.first != id) {
					q.pop();
				}
				pair<int, pair<int, int>> u = q.top();
				q.pop();
				ans += u.first;
//				cout << u.first << " ";
//				cout << 
				c[u.second.first]--;
				c[u.second.second]++;
			}
//			cout << id << " ";
		}
		cout << ans << "\n";
	}
	return 0;
} 

// T1 
//可以先反悔贪心
//贪心选最大的，然后如果超过限制，就选该集合里可以通过改变的最大的一个，然后就做完了。 
