#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans;

struct node {
	pair<int, int>b[5];
} a[100005];

struct stud {
	int x, y, z, id, cnt;
	friend bool operator> (stud X, stud Y) {
		int xx = max(X.y, X.z), yy = max(Y.y, Y.z);
		//	cout << xx << " " << yy << "\n";
		if (xx != yy)
			return xx < yy;
		return X.x > Y.x;
	}
};
priority_queue<stud, vector<stud>, greater<stud>>q[3];

void LosE(stud now) {
	now.cnt++;
	int nxt = a[now.id].b[now.cnt + 1].second;
	if (q[nxt].size() < n / 2)
		q[nxt].push({a[now.id].b[now.cnt + 1].first, a[now.id].b[(now.cnt + 2) % 4 + 1].first, a[now.id].b[(now.cnt + 3) % 4 + 1].first, now.id, now.cnt});
	else {
		if (now > q[nxt].top()) {
			q[nxt].push(now);
			now = q[nxt].top();
			q[nxt].pop();
			LosE(now);
		} else
			LosE(now);
	}
}

void dfs(int u, int cnta, int cntb, int cntc, int sum) {
	if (u == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	if (cnta < n / 2)
		dfs(u + 1, cnta + 1, cntb, cntc, sum + a[u].b[1].first);
	if (cntb < n / 2)
		dfs(u + 1, cnta, cntb + 1, cntc, sum + a[u].b[2].first);
	if (cntc < n / 2)
		dfs(u + 1, cnta, cntb, cntc + 1, sum + a[u].b[3].first);
}

struct AB {
	int x, y;
	friend bool operator > (AB X, AB Y) {
		int xx = X.y - X.x, yy = Y.y - Y.x;
		return xx < yy;
	}
};

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n <= 15) {
			ans = 0;
			for (int i = 1; i <= n; i++)
				cin >> a[i].b[1].first >> a[i].b[2].first >> a[i].b[3].first;
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		} else {
			bool fl = 1, fll = 1;
			for (int i = 1; i <= n; i++) {
				cin >> a[i].b[1].first >> a[i].b[2].first >> a[i].b[3].first;
				if (a[i].b[2].first || a[i].b[3].first)
					fl = 0;
				if (a[i].b[3].first)
					fll = 0;
			}
			if (fl) {
				priority_queue<int>pq;
				ans = 0;
				for (int i = 1; i <= n; i++)
					pq.push(a[i].b[1].first);
				for (int i = 1; i <= n / 2; i++) {
					ans += pq.top();
					pq.pop();
				}
				cout << ans << "\n";
			} else if (fll) {
				ans = 0;
				priority_queue<AB, vector<AB>, greater<AB>>pq;
				for (int i = 1; i <= n; i++) {
					AB tmp;
					tmp.x = a[i].b[1].first, tmp.y = a[i].b[2].first;
					pq.push(tmp);
					if (pq.size() > n / 2) {
						ans += pq.top().y;
						pq.pop();
					}
				}
				while (!pq.empty()) {
					ans += pq.top().x;
					pq.pop();
				}
				cout << ans << "\n";
			} else {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= 3; j++)
						a[i].b[j].second = j;
					sort(a[i].b + 1, a[i].b + 4, greater<pair<int, int>>());
				}
				for (int i = 1; i <= n; i++) {
					if (q[a[i].b[1].second].size() < n / 2)
						q[a[i].b[1].second].push({a[i].b[1].first, a[i].b[2].first, a[i].b[3].first, i, 0});
					else {
						stud now;
						now.id = i, now.x = a[i].b[1].first, now.y = a[i].b[2].first, now.z = a[i].b[3].first, now.cnt = 0;
						//int xx = max(q[a[i].b[1].second].top().y, q[a[i].b[1].second].top().z), yy = max(now.y, now.z);
						//cout << xx << " " << yy << "\n";
						if (now > q[a[i].b[1].second].top()) {
							q[a[i].b[1].second].push(now);
							now = q[a[i].b[1].second].top();
							q[a[i].b[1].second].pop();
							LosE(now);
						} else
							LosE(now);
					}
				}
				int res = 0;
				for (int id = 1; id <= 3; id++) {
					//	cout << id << ":";
					while (!q[id].empty()) {
						res += q[id].top().x;
						//		cout << q[id].top().id << " ";
						q[id].pop();
					}
					//	cout << "\n";
				}
				cout << res << "\n";
			}
		}
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/