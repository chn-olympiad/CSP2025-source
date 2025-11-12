#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int sum;
struct edge{
	int u,v;
	int s;
}e[1000005];
int c[1005];
bool cmp(edge a,edge b)
{
	return a.s>b.s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i = 1 ; i <= m ; i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].s;
		c[e[i].u]++;
		c[e[i].v]++;
		sum+=e[i].s;
	}
	for (int i = 1 ; i <= k*(n+1) ; k++) 
	{
		int t;
		cin>>t;
	}
	sort(e+1,e+m+1,cmp);
	int p = m;
	for (int i = 1 ; i <= m ; i++)
	{
		int u = e[i].u,v = e[i].v;
		if (c[u]>1&&c[v]>1)
		{
			c[u]--;
			c[v]--;
			sum-=e[i].s;
			p--;
		}
		if (p==n-1) break;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
