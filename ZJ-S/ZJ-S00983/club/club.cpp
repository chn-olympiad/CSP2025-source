#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e5 + 10, N1 = 210;
int a[4][N], n, f[N1 / 2][N1/ 2][N1 / 2];
void pts40()
{
	int ans = 0;
	for(int j = 0; j <= n / 2; j ++)
		for(int k = 0; k <= n / 2; k ++)
			for(int t = 0; t <= n / 2; t ++)
				f[j][k][t] = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = min(i, n / 2); j >= 0; j --)
			for(int k = min(i - j, n / 2); k >= 0; k --)
				for(int t = min(i - j - k, n / 2); t >= 0; t --)
				{
					int &now = f[j][k][t];
					if(j) now = max(now, f[j - 1][k][t] + a[1][i]);
					if(k) now = max(now, f[j][k - 1][t] + a[2][i]);
					if(t) now = max(now, f[j][k][t - 1] + a[3][i]);
					if(i == n) ans = max(ans, now);
				} 
	cout << ans <<"\n";
}
void Special_A()
{
	sort(a[1] + 1, a[1] + n + 1);
	int ans = 0;
	for(int i = 1; i <= n / 2; i ++) ans += a[1][i];
	cout << ans << "\n";
}
void Special_B_200()
{
	int ans = 0;
	for(int j = 0; j <= n / 2; j ++)
		for(int k = 0; k <= n / 2; k ++)
			f[j][k][0] = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = min(i, n / 2); j >= 0; j --)
			for(int k = min(i - j, n / 2); k >= 0; k --)
			{
				int &now = f[j][k][0];
				if(j) now = max(now, f[j - 1][k][0] + a[1][i]);
				if(k) now = max(now, f[j][k - 1][0] + a[2][i]);
				if(i == n) ans = max(ans, now);
			}
	cout << ans <<"\n";
}
struct Data
{
	int v, t, id;
	bool operator <(const Data &aa) const
	{
		if(v != aa.v) return v > aa.v;
		if(id != aa.id) return id < aa.id;
		return t < aa.t;
	}
}p[N];
bool st[N];
void I_want_more()
{
	int cnt[4] = {0, 0, 0, 0}, m = 0, ans = 0, vs[3] = {-1, -1, -1};
	queue<int> q[4], pq[4];
	for(int i = 1; i <= n; i ++) 
		for(int j = 1; j < 3; j ++)
			p[++ m] = {a[j][i], j, i}, st[i] = 0;
			
	sort(p + 1 , p + n + 1);
	for(int i = 1; i <= m && cnt[1] + cnt[2] <= n; i ++)
	{
		int v = p[i].v, id = p[i].id, t = p[i].t;
		if(st[id] || cnt[t] + q[t].size() == n / 2)
		{
			st[id] = 1;
			if(vs[t] == -1) vs[t] = v;
			continue;
		}
		st[id] = 1;
		if(id == p[i + 1].id && v == p[i + 1].v)
		{
			q[t].push(v), q[p[i + 1].t].push(p[i + 1].v);
			if(q[1].size() & 1 == 0)
			{
				while(q[1].size()) ans += q[1].front(), q[1].pop(), q[2].pop();
			}
			continue;
		}
		ans += v;
	}
	if(q[1].size())
	{
		if(vs[2] > vs[1]) ans += q[1].front() + vs[2];
		else ans += q[2].front() + vs[1];
	}
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T --)
	{
		cin >> n;
		int sig[4] = {0, 0, 0, 0};
		for(int i = 1; i <= n; i ++) 
			for(int j = 1; j < 4; j ++)
				cin >> a[j][i], sig[j] += a[j][i];
		if(n <= 30) pts40();
		else if(sig[2] == sig[3] && sig[3] == 0) Special_A();
		else if(sig[3] == 0 && n <= 200) Special_B_200();
		else I_want_more();
	}
	return 0;
}