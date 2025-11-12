#include <bits/stdc++.h>
using namespace std;
long long a[1020][1020];
long long b[11][1010],n;
bool flag[1010];
long long sum=0,tot=9999999999;
bool fa()
{
	for(long long i=1;i<=n;i++)
	{
		if(flag[i]==0)  return 0;
	}
	return 1;
}
void dfs(int x)
{
	flag[x]=1;
	for(long long i=1;i<=n;i++)
	{
		if(a[x][i]!=0&&flag[i]==0)
		{
			sum+=a[x][i];
			dfs(i);
			sum-=a[x][i];
		}
	}
	if(fa())
	{
		tot=min(sum,tot);
	}
	flag[x]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long q,w,c;
		cin>>q>>w>>c;
		a[q][w]=a[w][q]=c;
	}
	for(long long i=1;i<=k;i++)
	{
		for(long long j=0;j<=m;j++)
		{
			cin>>b[i][j];
		}
	}
	for(long long i=1;i<=n;i++) {
		dfs(i);
		sum=0;
		memset(flag,0,sizeof(flag));
	}
	cout<<tot;
	return 0;
}

