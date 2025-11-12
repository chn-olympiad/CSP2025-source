#include<bits/stdc++.h>
#define ll long long
using namespace std;
int u[1000010],v[1000010],w[1000010],c[100010];
int bj[10010][10010],bj2[10010],bj3[10010][10010];
int a[50][10010];
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	
	{
		for(int j=1;j<=n;j++)
		{
			bj2[i]=1e9;
			bj3[i][j]=1e9;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		bj[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		if(u[i]==i || v[i]==i)
		{
			bj2[i]=min(bj2[i],bj[u[i]][v[i]]);
		}
	}
	for(int q=1;q<=k;q++)
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bj3[i][j]=min(bj3[i][j],a[q][i]+a[q][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			bj2[i]=min(bj2[i],bj3[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cout<<bj2[i]<<" ";
		ans+=bj2[i];
	}
	cout<<ans<<'\n'; 
	return 0;
}

