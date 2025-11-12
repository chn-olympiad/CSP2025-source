//SN-S00766 韩心尧 西安滨河学校 
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m,k;
struct edge
{
	int u,v,w;
	friend bool operator<(edge a,edge b)
	{
		return a.w < b.w;
	}
}e[2200020];
int cnt;
int c[15];
int f[10020];
int vis[10020];
int cnte;
int ans = 1e18;
int find_x(int x)
{
	if (x == f[x])
	{
		return x;
	}
	return f[x] = find_x(f[x]);
}
void join_x(int x,int y)
{
	if(find_x(x) != find_x(y));
	f[find_x(x)] = find_x(y);
}
void add(int u,int v,int w)
{
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
}
int krl(vector<int> v)
{
	int tot = n + v.size(),res = 0;
	for (int i = 1;i <= n + k;i++)
	{
		f[i] = i;
	}
	for (int i = 1;i <= cnt;i++)
	{
		int u = e[i].u,to = e[i].v;
		if (u > to) swap(u,to);
		
		if (find_x(u) == find_x(to)) continue;
		if (to > n && find(v.begin(),v.end(),to - n ) == v.end()) continue;
		//printf("u = %d v = %d w = %d\n",u,to,e[i].w);
		join_x(u,to);
		res += e[i].w;
		
//		if ((u <= n && !vis[u] ))
//		{
//			tot--;
//			vis[u] = 1;
//			
//		}
//		if (to <= n || u <= n)
//		{
//			vis[to] = 1;
//		}
tot--;
		if (tot == 0)
		{
			break;
		}
	}
	return res;
}
void dfs(int p,int cst,vector<int> v)
{
	
	//printf("pos = %d village: ",p);
//	for (auto x : v)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
	int kl = krl(v);
	ans = min(ans,kl + cst);
	//printf("ans:%d = min(%d + %d)\n",ans,kl,cst);
	for (int i = p + 1;i <= k;i++)
	{
		v.push_back(i);
		dfs(i,cst + c[i],v);
		v.pop_back();
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
	cin >> n >> m >> k;
	
	for (int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		//add(v,u,w);
		
	}
	for (int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j++)
		{
			int w;
			cin >> w;
			add(j,n + i,w);
			//add(n  + i,j,w);
			
		}
	}
	sort(e + 1,e + cnt + 1);
	vector<int> v;
	dfs(0,0,v);
	cout<<ans;
	return 0;
 } 
