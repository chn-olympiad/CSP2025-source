#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+9,M = 1e6+9;
int n,m,k,c[N+1],s[M],ans;

struct edge
{
	int a;int b;
	int w;
	operator < (struct edge &a)const
	{
		return w < a.w;
	}
}edge[M];
struct vil
{
	int cost;
	int bridge[N];
}vil[11];
void add(struct edge &e)
{
	s[e.a] = 1;
	s[e.b] = 1;
	ans += e.w;
}
void djstar()
{
	for(int i  = 1; i <= m;++i)
	{
		if(!s[edge[i].a] ||!s[edge[i].b])add(edge[i]);
		cout << ans << endl;
	}
}
void solve()
{
	cin >>n>>m>>k;
	for(int i = 1 ;i <= m;++i)
	{
		cin >> edge[i].a;
		cin >> edge[i].b;
		cin >> edge[i].w;
	}
	for(int i = 1;i<=k;++i)
	{
		cin >> vil[i].cost;
		for(int j = 1;j<=n;++j)
		{
			cin >> vil[i].bridge[j];
		}
	}
	sort(edge+1,edge+m+1);
	djstar();
	cout << ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
