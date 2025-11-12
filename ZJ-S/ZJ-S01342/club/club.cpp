#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##END = (r); i <= i##END; i ++)
#define dwn(i, l, r) for (int i = (l), i##END = (r); i >= i##END; i --) 
#define int long long
using namespace std;

// luogu uid: 486677
// uid = 260985 shi xiao mao niang

const int N = 1e5 + 5;
int n, a[N][3], b[N][3], id[N];

struct Node{
	int x, id, now;
	bool operator < (const Node &nd) const{
		return x > nd.x;
	}
};
priority_queue<Node> q[3];

bool cmp(int x, int y){
	if (b[x][0] != b[y][0]) return b[x][0] > b[y][0];
	return b[x][1] > b[y][1];
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T --){
		cin >> n; rep(i, 0, 2) while (!q[i].empty()) q[i].pop();
		int ans = 0; rep(i, 1, n) rep(j, 0, 2) cin >> a[i][j];
		rep(i, 1, n) rep(j, 0, 2) b[i][j] = a[i][j];
		rep(i, 1, n) sort(b[i], b[i] + 3, greater<int>()), id[i] = i;
		sort(id + 1, id + n + 1, cmp);
		rep(tmp, 1, n){
			int i = id[tmp], w = -1;
			rep(j, 0, 2) if (b[i][0] == a[i][j]) w = j;
			q[w].push({b[i][0] - b[i][1], i, 0}); ans += b[i][0]; 
			if (q[w].size() > n / 2){
//				cout << w << "upd\n";
				Node u = q[w].top(); q[w].pop();
				ans -= u.x;
				int v = -1; rep(j, 0, 2){
					if (b[u.id][u.now + 1] == a[u.id][j] && j != w) v = j;
				} q[v].push({b[u.id][u.now + 1], u.id, u.now + 1});
			} //cout << ans << ' ';
		} cout << ans << '\n';
	}
	return 0;
}