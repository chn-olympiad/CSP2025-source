#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, id, id2;
};

bool operator<(node a, node b) {
	return a.x < b.x;
}
int a[200005][4];
priority_queue<node> q, c[4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		while (!q.empty())
			q.pop();
		while (!c[1].empty())
			c[1].pop();
		while (!c[2].empty())
			c[2].pop();
		while (!c[3].empty())
			c[3].pop();
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			q.push(node{a[i][1], i, 1});
			q.push(node{a[i][2], i, 2});
			q.push(node{a[i][3], i, 3});
		}
		int cnt[4] = {0}, vis[200005] = {0}, p[200005] = {0}, ans = 0;
		while (!q.empty()) {
			while (!c[1].empty() && cnt[c[1].top().id2] >= n / 2)
				c[1].pop();
			while (!c[2].empty() && cnt[c[2].top().id2] >= n / 2)
				c[2].pop();
			while (!c[3].empty() && cnt[c[3].top().id2] >= n / 2)
				c[3].pop();
			node tmp = q.top();
			q.pop();
			if (vis[tmp.id] == 1)
				continue;
			if (cnt[tmp.id2] < n / 2) {
				vis[tmp.id] = 1;
				cnt[tmp.id2]++;
				ans += tmp.x;
				p[tmp.id] = tmp.id2;
				if (tmp.id2 != 1)
					c[tmp.id2].push(node{a[tmp.id][1] - tmp.x, tmp.id, 1});
				if (tmp.id2 != 2)
					c[tmp.id2].push(node{a[tmp.id][2] - tmp.x, tmp.id, 2});
				if (tmp.id2 != 3)
					c[tmp.id2].push(node{a[tmp.id][3] - tmp.x, tmp.id, 3});
				//cout << tmp.id << " " << tmp.id2 << endl;
			} else if (!c[tmp.id2].empty() && c[tmp.id2].top().x > -tmp.x) {
				ans += c[tmp.id2].top().x;
				ans += tmp.x;
				cnt[c[tmp.id2].top().id2]++;
				p[c[tmp.id2].top().id] = c[tmp.id2].top().id2;
				vis[tmp.id] = 1;
				//cout << c[tmp.id2].top().id << " " << tmp.id2 << "->" << c[tmp.id2].top().id2 << endl;
				//cout << tmp.id << " " << tmp.id2 << endl;
				int tmp2 = c[tmp.id2].top().id;
				c[tmp.id2].pop();
				while (!c[1].empty() && p[c[1].top().id] != 1)
					c[1].pop();
				while (!c[2].empty() && p[c[2].top().id] != 2)
					c[2].pop();
				while (!c[3].empty() && p[c[3].top().id] != 3)
					c[3].pop();
				if (tmp.id2 != 1)
					c[tmp.id2].push(node{a[tmp.id][1] - tmp.x, tmp.id, 1});
				if (tmp.id2 != 2)
					c[tmp.id2].push(node{a[tmp.id][2] - tmp.x, tmp.id, 2});
				if (tmp.id2 != 3)
					c[tmp.id2].push(node{a[tmp.id][3] - tmp.x, tmp.id, 3});
				if (p[tmp2] != 1 && tmp.id2 != 1 && a[tmp2][1] <= a[tmp2][p[tmp2]])
					c[p[tmp2]].push(node{a[tmp2][1] - a[tmp2][p[tmp2]], tmp2, 1});
				if (p[tmp2] != 2 && tmp.id2 != 2 && a[tmp2][2] <= a[tmp2][p[tmp2]])
					c[p[tmp2]].push(node{a[tmp2][2] - a[tmp2][p[tmp2]], tmp2, 2});
				if (p[tmp2] != 3 && tmp.id2 != 3 && a[tmp2][3] <= a[tmp2][p[tmp2]])
					c[p[tmp2]].push(node{a[tmp2][3] - a[tmp2][p[tmp2]], tmp2, 3});
			}
		}
		cout << ans << endl;
	}
	return 0;
}
