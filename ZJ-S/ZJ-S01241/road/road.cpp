#include <bits/stdc++.h>
using namespace std;
long long t[10005][10005],a[10004],c;
long long ans;
bool f[10005];
int n,m,k,u,v,w;
void r(int x,long long sum,int num)
{
	if (ans!=-1 && sum>ans)
		return;
	int tmp=0;
	for (int i=1;i<=n;i++)
	{
		if (i==x || f[i] || t[x][i]==0)
			continue;
		if (tmp==0 || t[x][tmp]>t[x][i])
			tmp=i;
	}
		
	if (tmp==0)
		return;
	if (num==n-2)
	{
		if (ans==-1)
			ans=sum+t[x][tmp];
		else
			ans=min(ans,sum+t[x][tmp]);
		return;
	}
	f[tmp]=true;
	for (int i=1;i<=n;i++)
		if (f[i])
			r(i,sum+t[x][tmp],num+1);
	f[tmp]=false;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=-1;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		t[u][v]=w;
		t[v][u]=w;
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++)
//		{
//			cout<<t[i][j]<<' ';
//		}
//		cout<<'#'<<endl;
//	}
	f[1]=true;
	r(1,0,0);
	cout<<ans;
	return 0;
}
