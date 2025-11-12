#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 1e4+55,M = 3e6+9999,K = 15;
ll cost[K][N];
int head[M],nx[M],fr[M],to[M];
ll wa[M];
#define min(a,b) ((a<b) ? a:b)
// solve1
int f[M],so[M];
inline int get(int x)
{
	if(x == f[x])return x;
	return f[x] = get(f[x]);
}
inline bool cmp(int a,int b)
{
	return wa[a] < wa[b];
}
void solve(); 

// solve2
void solve2();

// last solve
vector<pair<int,ll> >vv;
void solvela();
void soll();
int n,m,k,cne;
inline void push(int f,int t,ll w)
{
	cne++;
	nx[cne] = head[f];
	head[f] = cne;
	fr[cne] = f;
	to[cne] = t;
	wa[cne] = w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		ll w;
		cin >> u >> v >> w;
		push(u,v,w);
	}
	bool fl = 1;
	for(int i = 1;i <= k;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cin >> cost[i][j];
		}
		if(cost[i][0])fl = 0;
	}
	if(fl)
	{
		solve2();return 0;
	}
	if(k == 0)
	{
		solve();return 0;
	}
	solvela();
//	soll();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void init(int s,ll ans)
{
	for(int i = 0;i <= n+k;i++)
	{
		f[i] = i;
	}
	ll aans = 0;
	for(int j = 1;j <= k;j++)
	{
		if(s & (1 << (j-1)))
		{
			aans += cost[j][0];
			for(int l = 1;l <= n;l++)
			{
				push(j+n,l,cost[j][l]);
			}
		}
	}
	for(int i = 1;i <= cne;i++)
	{
		so[i] = i;
	}
	sort(so+1,so+cne+1,cmp);
	for(int i = 1;i <= cne;i++)
	{
		int j = so[i];
		int x = get(fr[j]),y = get(to[j]);
		if(x != y)
		{
			aans += wa[j];
			f[x] = y; 
		}
	}
	if(aans <= ans)
	{
		vv.push_back({s,aans});
	}
}
void soll()
{
	
	ll ans = 0;
	int cnt = 0;
	int cnk = cne;
	{
		for(int i = 0;i <= n;i++)
		{
			f[i] = i;
		}
		for(int i = 1;i <= cne;i++)
		{
			so[i] = i;
		}
		sort(so+1,so+cne+1,cmp);
		int cnt = 0;
		for(int i = 1;i <= cne;i++)
		{
			int j = so[i];
			int x = get(fr[j]),y = get(to[j]);
			if(x != y)
			{
				ans += wa[j];
				f[x] = y; 
				cnt ++;
			}
			if(cnt == n-1)break;
		}
	}
	cne = cnk; 
	vv.push_back({0,ans});
	for(int i = 1;i <= k;i++)
	{
		int l = vv.size();
		for(int i = 0;i < l;i++)
		{
			int s = vv[i].first;
			ll ans = vv[i].second;
			s += 1<<(i-1);
			init(s,ans);
		}
	}
	for(int i = 0;i <= vv.size();i++)
	{
		ans = min(ans,vv[i].second);
	}
	cout << ans << endl;
}
void solve()
{
	ll ans = 0;
	for(int i = 0;i <= n;i++)
	{
		f[i] = i;
	}
	for(int i = 1;i <= cne;i++)
	{
		so[i] = i;
	}
	sort(so+1,so+cne+1,cmp);
	int cnt = 0;
	for(int i = 1;i <= cne;i++)
	{
		int j = so[i];
		int x = get(fr[j]),y = get(to[j]);
		if(x != y)
		{
			ans += wa[j];
			f[x] = y; 
			cnt ++;
		}
		if(cnt == n-1)break;
	}
	cout << ans << endl;
}
void solve2()
{
	for(int i = 1;i <= k;i++)
	{
		int kk = -1;
		for(int j = 1;j <= n;j++)
		{
			if(cost[i][j] == 0)
			{
				kk = j;break;
			}
		}
		for(int j = 1;j <= n;j++)if(j != kk)
		{
			push(kk,j,cost[i][j]);
		}
	}
	ll ans = 0;
	for(int i = 0;i <= n;i++)
	{
		f[i] = i;
	}
	for(int i = 1;i <= cne;i++)
	{
		so[i] = i;
	}
	sort(so+1,so+cne+1,cmp);
	int cnt = 0;
	for(int i = 1;i <= cne;i++)
	{
		int j = so[i];
		int x = get(fr[j]),y = get(to[j]);
		if(x != y)
		{
			ans += wa[j];
			f[x] = y; 
			cnt ++;
		}
		if(cnt == n-1)break;
	}
	cout << ans << endl;
}
void solvela()
{
	int s = 1<<k;
	ll ans = 2e18;
	const int cnk = cne;
	for(int i = 0;i < s;i++)
	{
		cne = cnk;
		ll aans = 0;
		int ccnt = 0;//
		bool fff  = 0;
		for(int j = 1;j <= k;j++)
		{
			if(i & (1 << (j-1)))
			{
				ccnt++;
				aans += cost[j][0];
				if(aans >= ans)
				{
					fff = 1;goto I;
				}
				for(int l = 1;l <= n;l++)
				{
					push(j+n,l,cost[j][l]);
				}
			}
		}
		I:
		if(fff)continue;
		for(int i = 0;i <= n+k;i++)
		{
			f[i] = i;
		}
		for(int i = 1;i <= cne;i++)
		{
			so[i] = i;
		}
		sort(so+1,so+cne+1,cmp);
		int cnt = 0;
		for(int i = 1;i <= cne;i++)
		{
			int j = so[i];
			int x = get(fr[j]),y = get(to[j]);
			if(x != y)
			{
				
				aans += wa[j];
				f[x] = y; 
				cnt ++;
			}
			if(cnt == n+ccnt-1)break;
			if(aans >= ans)break;
		}
		ans = min(ans,aans);
	}
	cout << ans << endl;
}
