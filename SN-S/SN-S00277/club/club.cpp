#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 114;
int n;
struct elem {
	int x, v;
	void read(const int i) {x = i, cin >>v;}
	bool operator<(const elem o) const {return v > o.v;}
} a[N][5];
struct qtype {
	int x, y, v;
	bool operator<(const qtype o) const {return v > o.v;}
};
priority_queue<qtype> q[5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >>t;
	while(t--) {
		cin >>n;
		for(int j = 0; j < 3; ++j) while(!q[j].empty()) q[j].pop();
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 3; ++j) a[i][j].read(j);
			sort(a[i], a[i] + 3);
			sum += a[i][0].v;
			q[a[i][0].x].push({i, 0, a[i][0].v - a[i][1].v});
		}
		while(true) {
			int _j = 0;
			for(int j = 0; j < 3; ++j) if((int)q[j].size() > (n >> 1)) {_j = j; goto label;}
			break; label:;
			while((int)q[_j].size() > (n >> 1)) {
				const auto u = q[_j].top(); q[_j].pop();
				sum += a[u.x][u.y + 1].v - a[u.x][u.y].v;
				if(u.y == 1) q[a[u.x][u.y + 1].x].push({u.x, 3, INT_MAX});
				else q[a[u.x][u.y + 1].x].push({u.x, u.y + 1, a[u.x][u.y + 1].v - a[u.x][u.y + 2].v});
			}
		}
		cout <<sum <<'\n';
	}
	return 0;
}
