#include<bits/stdc++.h>
using namespace std;

int n, m, k;

int pre[10010];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

long long ans = 0;

bool cmp(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b ) {
	return a.first > b.first;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for ( int i = 1; i <= n; i++ ) pre[i] = i;
	priority_queue<pair<int, pair<int, int > > , vector<pair<int, pair<int, int > > >, greater<pair<int, pair<int, int > > > > pq;
	for ( int i = 1; i <= m; i++ ) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		pq.push(make_pair(w, make_pair(u, v)));
	}
	for ( int i = 1; i <= k; i++ ) {
		int cost;
		cin >> cost;
		for ( int j = 1; j <= n; j++ ) {
			int tmp;
			cin >> tmp;
			pq.push(make_pair(tmp, make_pair(i, j)));
		}
	}
	
	int cnt = 0;
	
	while ( !pq.empty() && cnt != n - 1 ) {
		pair<int, pair<int, int > > p = pq.top();
		pq.pop();
		int u = p.second.first, v = p.second.second;
		if ( find(u) != find(v) ) {
			ans += p.first, cnt++;
		}
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
