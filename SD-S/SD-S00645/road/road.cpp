#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 1000;
const int maxm = 1e6 + 1e5;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
	return x * f;
}
inline void write(ll x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return;
}
struct note{
	int u,v,w;
}edg[maxm];
bool cmp(note x,note y) {return x.w < y.w;}
int c[20];
int fa[maxn];
int getf(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = getf(fa[x]);
}
vector<note> vec;
vector<note> bian[maxn];
ll ans;

int n,m,k;
void solve(int s)
{
	vector<note> g;g.clear();
	for(auto it : vec) g.push_back(it);
	ll res = 0;
	int cnt = 0;
	for(int i = 1;i <= k;i++)
		if(s & (1 << (i - 1)))
		{
			res += c[i];
			cnt++;
			for(auto it : bian[i]) g.push_back(it);
		}
	sort(g.begin(),g.end(),cmp);
	for(int i = 1;i <= n + 11;i++) fa[i] = i;
	int num = n + cnt;
	int ct = 0;
	for(auto it : g)
	{
		int u = it.u,v = it.v,w = it.w;
		u = getf(u),v = getf(v);
		if(u == v) continue;
		fa[u] = v;
		res += w;
		if(++ct == num - 1) break;
	}
	ans = min(ans,res);
	return;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1;i <= m;i++)
	{
		int u = read(),v = read(),w = read();
		edg[i] = {u,v,w};
	}
	sort(edg + 1,edg + m + 1,cmp);
	for(int i = 1;i <= n + 11;i++) fa[i] = i;
	int all = 0;
	ans = 0;
	for(int i = 1;i <= m;i++)
	{
		int u = edg[i].u,v = edg[i].v,w = edg[i].w;
		u = getf(u),v = getf(v);
		if(u == v) continue;
		fa[u] = v;vec.push_back(edg[i]);
		ans += w;
		if(++all == n - 1) break;
	}
	
	for(int i = 1;i <= k;i++)
	{
		c[i] = read();
		for(int j = 1;j <= n;j++)
		{
			int x = read();
			bian[i].push_back({n + i,j,x});
		}
	}
	
	for(int s = 0;s < (1 << k);s++) solve(s);
	write(ans);
	return 0;
}
