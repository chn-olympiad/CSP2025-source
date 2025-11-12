#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	gxk::main();
	return 0;
}

#define int long long
namespace gxk {
	const int maxn = 100010;
	
	int T, n, ans;
	struct ren {
		int v[3];
		void shiruoyu() {
			if (v[0] < v[1]) swap(v[0], v[1]);
			if (v[1] < v[2]) swap(v[1], v[2]);
			if (v[0] < v[1]) swap(v[0], v[1]);
			return ;
		}
	} r[maxn];
	vector <int> p[3];
	priority_queue <int, vector <int>, greater <int> > q;
	
	void main() {
		cin >> T;
		while (T--) {
			cin >> n;
			p[0].clear();
			p[1].clear();
			p[2].clear();
			ans = 0;
			for (int i = 1; i <= n; i++) {
				cin >> r[i].v[0] >> r[i].v[1] >> r[i].v[2];
				if (r[i].v[0] >= r[i].v[1] && r[i].v[0] >= r[i].v[2]) {
					p[0].push_back(i);
					ans += r[i].v[0];
				} else if (r[i].v[1] >= r[i].v[2]) {
					p[1].push_back(i);
					ans += r[i].v[1];
				} else {
					p[2].push_back(i);
					ans += r[i].v[2];
				}
				r[i].shiruoyu();
			}
			while (!q.empty()) q.pop();
			if (p[0].size() > n / 2) {
				for (int j = 0; j < p[0].size(); j++) {
					int i = p[0][j];
					q.push(r[i].v[0] - r[i].v[1]);
				}
			} else if (p[1].size() > n / 2) {
				for (int j = 0; j < p[1].size(); j++) {
					int i = p[1][j];
					q.push(r[i].v[0] - r[i].v[1]);
				}
			} else if (p[2].size() > n / 2) {
				for (int j = 0; j < p[2].size(); j++) {
					int i = p[2][j];
					q.push(r[i].v[0] - r[i].v[1]);
				}
			}
			while (q.size() > n / 2) {
				ans -= q.top();
				q.pop();
			}
		cout << ans << '\n';
		}
	}
}
