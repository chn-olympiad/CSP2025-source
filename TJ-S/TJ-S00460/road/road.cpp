#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;
struct EDGE {
	long long u, v, w;
};
vector<EDGE> edge1, edge2;
int n, m, k, c[10], a[10][maxn];
int fa[maxn + 10], sz[maxn + 10];
bool cmp(EDGE a, EDGE b) {
	return a.w < b.w;
}
int find(int x) {
	if(x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(sz[fx] > sz[fy]) swap(fx, fy);
	fa[fx] = fy;
	sz[fy] += sz[fx];
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
        cin.tie(nullptr);

	long long ANS = 2e18;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		edge1.push_back({u, v, w});
	}
	sort(edge1.begin(), edge1.end(), cmp);
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for(int w = 0; w < (1 << k); w++) {
		for(int i = 0; i <= n + 10; i++) {
			fa[i] = i;
			sz[i] = 1;
		}
		edge2.clear();
		long long ans = 0;
		int nn = n;
		for(int i = 0; i < k; i++) {
			if(w >> i & 1) {
				nn++;
				ans += c[i];
				for(int j = 1; j <= n; j++) {
					edge2.push_back({nn, j, a[i][j]});
				}
			}
		}
		sort(edge2.begin(), edge2.end(), cmp);
		int pos = 0, cnt = 0;
		for(int i = 0; i < m; i++) {
			while(pos < edge2.size() && edge2[pos].w < edge1[i].w) {
				int u = edge2[pos].u, v = edge2[pos].v, w = edge2[pos].w;
				pos++;
				int fu = find(u);
				int fv = find(v);
				if(fu != fv) {
					ans += w;
					cnt++;
					merge(fu, fv);
					if(cnt == nn - 1) break;
				}
			}
			//cerr << i << " " << pos << " " << cnt << " " << ans << endl;
			if(cnt == nn - 1) break;
			//merge edge1
			int u = edge1[i].u, v = edge1[i].v, w = edge1[i].w;
			//cerr << u << " " << v << " " << w << endl;
			int fu = find(u);
			int fv = find(v);
			if(fu != fv) {
				ans += w;
				cnt++;
				merge(fu, fv);
				if(cnt == nn - 1) break;
			}
		}
		//cerr << w << " " << ans << endl;
		ANS = min(ANS, ans);
	}
	cout << ANS << endl;
	return 0;
}
