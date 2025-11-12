#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
const int root = 10050;
int n;
int m;
int k;
long long ans = LLONG_MAX;
vector< tuple<int,int,int> > vec;
vector< tuple<int,int,int> > tmp;
int a[15][10055];
int fa[10055];
int find(int x)
{
	if(fa[x] == x)
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
bool merge(int x, int y)
{
	int xx = find(x);
	int yy = find(y);
	if(xx == yy)
	{
		return false;
	}
	fa[xx] = yy;
	return true;
}
int Dij()
{
	int res = 0;
	tmp = vec;
	for(int i = 1; i<=n+k; i++)
	{
		fa[i] = i;
	}
	fa[root] = root;
	sort(tmp.begin(),tmp.end());
	for(auto e : tmp)
	{
		int w = get<0>(e);
		int u = get<1>(e);
		int v = get<2>(e);
		if(merge(u,v))
		{
			res+=w;
		}
	}
	return res;
}
int main()
{
	fre();
	cin>>n>>m>>k;
	for(int i = 1; i<=m; i++)
	{
		int u;
		int v;
		int w;
		cin>>u>>v>>w;
		vec.push_back(make_tuple(w,u,v));
	}
	for(int i = 1; i<=k; i++)
	{
		for(int j = 0; j<=n; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 0; i<(1<<k); i++)
	{
		long long res = 0;
		for(int j = 1; j<=k; j++)
		{
			if((i>>(j-1))&1)
			{
				for(int v = 1; v<=n; v++)
				{
					vec.push_back(make_tuple(a[j][v],n+j,v));
				}
				res+=a[j][0];
			}
		}
		res+=Dij();
		ans = min(ans,res);
		for(int j = 1; j<=k; j++)
		{
			if((i>>(j-1))&1)
			{
				for(int v = 1; v<=n; v++)
				{
					vec.pop_back();
				}
			}
		}
	}
	cout<<ans;
	return 0;
}