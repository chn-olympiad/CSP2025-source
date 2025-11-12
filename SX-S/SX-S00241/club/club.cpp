#include <bits/stdc++.h>
#define ll long long
#define P pair<long long,long long>
#define fi first
#define se second

using namespace std;
const int N = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f;

ll T;
ll n;
ll arr[N][4];
ll ans;
ll a, b, c;

struct stu {
	ll a, b, c;
};
stu e[N];

namespace e1 {

	void dfs(ll step, ll sum1, ll sum2, ll sum3) {
		if (step > n) {
			ans = max(ans, sum1 + sum2 + sum3);
			//cout << ans << " " << sum1 << " " << sum2 << " " << sum3 << endl;
			return ;
		}
		//for (ll i = step; i <= n; i++) {
		if (a < n / 2) {
			a++;
			dfs(step + 1, sum1 + arr[step][1], sum2, sum3);
			a--;
		}
		if (b < n / 2) {
			b++;
			dfs(step + 1, sum1, sum2 + arr[step][2], sum3);
			b--;
		}
		if (c < n / 2) {
			c++;
			dfs(step + 1, sum1, sum2, sum3 + arr[step][3]);
			c--;
		}
		//}
	}
	void solve() {
		a = b = c = 0;
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}
}

ll brr[N], crr[N];

namespace e2 {
	void solve() {
		for (ll i = 1; i <= n; i++) {
			brr[i] = arr[i][1];
		}
		sort(brr + 1, brr + n + 1);
		for (ll i = n; i >= n / 2; i--) {
			ans += brr[i];
		}
		cout << ans << endl;
	}
}


namespace e4 {
	priority_queue<P, vector<P> > q1;
	priority_queue<P, vector<P> > q2;
	priority_queue<P, vector<P> > q3;
	bool vis[N];
	ll t1, t2, t3;
	void solve() {
		while (!q1.empty())
			q1.pop();
		while (!q2.empty())
			q2.pop();
		while (!q3.empty())
			q3.pop();
		memset(vis, 0, sizeof(vis));
		t1 = t2 = t3 = 0;
		for (ll i = 1; i <= n; i++) {
			q1.push({arr[i][1], i});
			q2.push({arr[i][2], i});
			q3.push({arr[i][3], i});
		}
		ll i = n;
		while (i >= 1) {
			while (vis[q1.top().se] && !q1.empty()) {
				q1.pop();
			}
			while (vis[q2.top().se] && !q2.empty()) {
				q2.pop();
			}
			while (vis[q3.top().se] && !q3.empty()) {
				q3.pop();
			}
			ll a = q1.top().fi, id1 = q1.top().se;
			ll b = q2.top().fi, id2 = q2.top().se;
			ll c = q3.top().fi, id3 = q3.top().se;
			if (t1 >= n / 2)
				a = 0;
			if (t2 >= n / 2)
				b = 0;
			if (t3 >= n / 2)
				c = 0;
			//cout << a << " " << b << " " << c << endl;
			if (a >= b && a >= c && t1 < n / 2) {
				t1++;
				ans += a;
				q1.pop();
				vis[id1] = 1;
			} else if (b >= a && b >= c && t2 < n / 2) {
				t2++;
				ans += b;
				q2.pop();
				vis[id2] = 1;
			} else if (c >= a && c >= b && t3 < n / 2) {
				q3.pop();
				t3++;
				ans += c;
				vis[id3] = 1;
			}
			//cout << ans << endl;
			i--;
		}
		cout << ans << endl;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		bool f = 0;
		bool f1 = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
			e[i].a = arr[i][1], e[i].b = arr[i][2], e[i].c = arr[i][3];
			if (arr[i][2] != 0 || arr[i][3] != 0)
				f = 1;
		}
//		if (n <= 10) {
//			e1::solve();
//		} else if (!f) {
//			e2::solve();
//		} else {
//			e4::solve();
//		}
		e4::solve();
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

