#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 200005
using namespace std;
bool cmp(point x,point y)
{
	return x.q <y.q;
}
struct point
{
	int w;
	int u;
	int q;
} p[1000006];
int c[11][MAXN], t[1000006];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	bool b=0;
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++)
	{
		cin >> p[i].w >> p[i].u >> p[i].q;
	}
	sort(p+1,p+m+1,cmp);
	for(int i=0; i<k; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin >> c[k][j];
		}
	}
	for(int i=1; i<=m; i++)
	{
		if(t[p[i].w]==0&&t[p[i].u]==0)
		{
			t[p[i].w]=1;
			t[p[i].u]=1;
			ans+=p[i].q;
		}
		if(t[p[i].w]==1&&t[p[i].u]==0)
		{
			t[p[i].u]=1;
			ans+=p[i].q;
			bool =1;
		}
		if(t[p[i].w]==0&&t[p[i].u]==1)
		{
			t[p[i].w]=1;
			ans+=p[i].q;
			b = 1;
		}
		if(t[p[i].w]==1&&t[p[i].u]==1&&b=0)
		{
		ans+=p[i].q;
		}
			if(t[p[i].w]==1&&t[p[i].u]==1&&b=1)
		{
		continue;
		}
	}
	cout << ans;
	return 0;
}
