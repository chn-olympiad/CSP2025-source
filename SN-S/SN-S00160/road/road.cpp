#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,k;
struct poi{
	int u,v=1e9,sum;
	bool f=0;
}a[10005][10005];
int b[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int aa;
		cin>>aa;
		a[aa][0].sum++;
		cin>>a[aa][a[aa][0].sum].u>>a[aa][a[aa][0].sum].v;
		if(a[aa][a[aa][0].sum].v<a[aa][0].v)
		{
			a[aa][0].v=a[aa][a[aa][0].sum].v;
			a[aa][0].u=a[aa][a[aa][0].sum].u;
		}
	}
	for(int i=1;i<=k;i++)
	{
		b[i][0]=100000000;
		int bb;
		cin>>bb;
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
			b[i][j]+=bb;
			if(b[i][j]<b[i][0])b[i][0]=b[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0].f) continue;
		int mi=1e9;
		for(int j=1;j<=k;j++)
		{
			if(b[j][i]<mi)mi=b[j][i];
		}
		if(a[i][0].v<mi)
		{
			ans+=a[i][0].v;
			a[a[i][0].u][0].f=1;
		}
		else ans+=mi;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
