#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct lu {
	int v, w;
	bool operator < (const lu &rhs)const {
		return rhs.w < w;
	}
};
int a[N];
int dis[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	//ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<lu> > G(n + 10);
	priority_queue<lu> q;
	int fl = 0;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		//cout << i;
		cin >> u >> v >> w;
		lu x;
		x.v = v;
		x.w = w;
		G[u].push_back(x);
		x.v = u;
		G[v].push_back(x);
		//cout << G[u][1].v << "\n";
		if (fl == 0) {
			q.push(x);
			//	cout << q.top().v << " ";
			fl = 1;
			//cout << "hjv" << q.top().v << "kj";
		}
		//q.push(G[i]);
	}

	int c;
	cin >> c;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}


	for (int i = 1; i <= N - 3; i++) {
		dis[i] = -1;
	}

	auto asd = q.top();
	//cout << asd.v;
	dis[asd.v] = 0;
//	cout << "jbkjb";
	int cnt = 1;
	int ans = 0;
	while (q.size()) {
//		priority_queue<lu> p = q;
//		while (p.size()) {
//			auto x = p.top();
//			p.pop();
//			cout << x.v << " " << x.w << "\n";
//		}
		//cout << "\n\n\n\n";
		//cout << q.size() << "\n";
		if (cnt > n)
			break;
		auto x = q.top();
		q.pop();

		//for (auto xx : q) {
		//	cout << xx.v << " " << xx.w << "\n";
		//}
		if (dis[x.v] != -1) {
			ans += x.w;
			for (auto xx : G[x.v]) {
				//cout << xx.w << " ";
				if (dis[xx.v] == -1) {
					q.push(xx);

					//	cout << xx.w;
					dis[xx.v] = 1;

				}
			}
			cnt++;
			//cout << "\n";
		}
		//cout << x.v << " " << x.w << "\n";

	}

//	for (int i = 1; i <= m; i++) {
//		ans += max(0, dis[i]);
//		cout << i << " ";
//	}
	cout << ans;


	return 0;
}