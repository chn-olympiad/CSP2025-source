#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<pair<int, int> > G[N];
int f[N];
pair<int, pair<int, int> > d[N];
int n, m, k;
int ans;
int find(int x)
{
	if(f[x] == x) return f[x];
	return f[x] = find(f[x]);
}
void add(int x, int y)
{
	int xx = find(x), yy = find(y);
	f[xx] = f[yy];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i)
	{
		int x, y, z;
		cin >> d[i].second.first >> d[i].second.second >> d[i].first;
	}
	for(int i = 1; i <= n; ++i) f[i] = i;
	sort(d + 1, d + m + 1);
	for(int i = 1; i <= m; ++i)
	{
		if(find(d[i].second.first) == find(d[i].second.second)) continue;
		ans += d[i].first;
//		cout << find(d[i].second.first) << " " << find(d[i].second.second) << " " << d[i].first << " " << d[i].second.first<< " " << d[i].second.second << '\n';
		add(d[i].second.first, d[i].second.second);
	}
	cout << ans;
	return 0;
}

