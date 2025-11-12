#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 5e5 + 10, M = 1e6 + 10;
int a[N], n, k, s[N];
struct Data { int x, y; };
bool st[M];
map<int, int> mp;
int idx;
int f(int x)
{
	if(mp[x]) return mp[x];
	return mp[x] = ++ idx;
}
vector<int> g[N];
void solve()
{
	for(int i = 1; i <= n; i ++) g[f(s[i])].push_back(i);
	vector<Data> p;
	for(int i = 1; i <= n; i ++)
		if(mp[k ^ s[i - 1]])
		{
			int v = f(k ^ s[i - 1]);
			int j = lower_bound(g[v].begin(), g[v].end(), i) - g[v].begin();
			if(j == g[v].size()) continue; 
			p.push_back({i, g[v][j]});
		}
	priority_queue<PII> q;
	for(int i = 0; i < p.size(); i ++)
	{
		while(q.size() && p[i].y <= q.top().first) st[q.top().second] = 1, q.pop();
		q.push({p[i].y, i});
	}
	int ans = 0;
	for(int i = 0, lst = -1; i < p.size(); i ++)
		if(!st[i])
		{
			if(lst != -1 && p[i].x <= p[lst].y) continue;
			ans ++, lst = i;
		}
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
	solve();
	return 0;
}
