#include <bits/stdc++.h>
#define int long long
using namespace std;

int t = 1;

const int N = 1e4 + 10;
int n, F[N], ans;
int m, a, b, c;
int K, C[15];
pair <int, int> A[15][N];
priority_queue<pair <pair <int, int>, pair <int, int> >, vector <pair <pair <int, int>, pair <int, int> > >, greater<pair <pair <int, int>, pair <int, int> > > > PQ;

bool cmp(pair <int, int> a, pair <int, int> b) {
	return a.first < b.first;
}

int find(int x) {
	if(F[x] == x) return x;
	return F[x] = find(F[x]);
}

void solve() {
	cin >> n >> m >> K;
	for(int i = 1; i <= m; i ++) {
		cin >> a >> b >> c;
		PQ.push({{c, 0}, {a, b}});
	}
	for(int i = 1; i <= K; i ++) {
		cin >> C[i];
		for(int j = 1; j <= n; j ++) cin >> A[i][j].first, A[i][j].second = j;
		sort(A[i] + 1, A[i] + n + 1, cmp);
		PQ.push({{C[i] + A[i][1].first + A[i][2].first, i}, {A[i][1].second, A[i][2].second}});
	}
	
	for(int i = 1; i <= n; i ++) F[i] = i;
	while(PQ.size()) {
		auto i = PQ.top(); PQ.pop();
		int w = i.first.first, p = i.first.second, x = i.second.first, y = i.second.second;
//		cerr<<w<<" "<<p<<" "<<x<<" "<<y<<"\n";
		
		if(find(x) == find(y)) continue;
		F[find(x)] = find(y);
		ans += w;
		
		if(0 == p) continue;
		for(int j = 1; j <= n; j ++) {
			for(int k = j + 1; k <= n; k ++) {
				if(1 == j && 2 == k) continue;
				PQ.push({{A[p][j].first + A[p][k].first, 0}, {A[p][j].second, A[p][k].second}});
			}
		}
	}
	cout << ans;
}

signed main() {
//	freopen("road4.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while(t --) {
		solve();
	}
	return 0;
}
