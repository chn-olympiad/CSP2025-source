#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e+4 + 20;
const int maxm = 1e+6 + 6;
int fa[maxn];
int c[20], a[20][maxn];
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
vector<pair<int, pair<int, int> > > vec;

inline ll read() {
	ll ref = 0;
	bool f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = 0;
		ch = getchar();
	}
	while(isdigit(ch))
		ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
	return (f ? ref : -ref);
} 

int find(int i) {
	if(!fa[i]) return i;
	return fa[i] = find(fa[i]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n = read(), m = read(), k = read();
	ll ans = 0;
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		q.push(make_pair(w, make_pair(u, v)));
	}
	for(int i = 0; i < k; i++) {
		c[i] = read();
		for(int j = 1; j <= n; j++) a[i][j] = read();
	}
	while(!q.empty()) {
		int w = q.top().first;
		int u = q.top().second.first;
		int v = q.top().second.second;
		q.pop();
		if(find(u) == find(v)) continue;
		vec.push_back(make_pair(w, make_pair(u, v)));
		ans += w;
		fa[find(u)] = find(v);
	}
	for(int rp = 1; rp < 1 << k; rp++) {
//		cout << rp << endl;
		memset(fa, 0, sizeof fa);
		ll answer = 0;
		for(auto i : vec) q.push(i);

		for(int i = 0; i < k; i++) 
			if(rp >> i & 1) {
				answer += c[i];
				for(int j = 1; j <= n; j++) 
					q.push(make_pair(a[i][j], make_pair(n + i + 1, j)));
			}

		while(!q.empty()) {
			int w = q.top().first;
			int u = q.top().second.first;
			int v = q.top().second.second;
			q.pop();
			if(find(u) == find(v)) continue;
			answer += w;
			fa[find(u)] = find(v);
		}
//		cout << (bitset<5>)(rp) << ' ' << answer << endl;
		ans = min(answer, ans);
	}
	cout << ans;

	return 0;
}
