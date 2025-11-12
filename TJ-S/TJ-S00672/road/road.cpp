#include <bits/stdc++.h> 
using namespace std;
long long mp[1005][1005];
bool mz[10005][10005];
long long a[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,c=0;
	cin>>n>>m>>k;
	for(long long i=0;i<m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mz[u][v]=w;
		c+=w;
	}
	/*
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			mz[i][j]=false;
		}
	}
	for(long long i=0;i<n;i++)
	{
		mp[i][i]=0;
		mz[i][i]=true;
	}
	
	for(long long i=0;i<k;i++)
	{
		long long c=0;
		cin>>c;
		for(long long j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			for(long long g=0;g<n;g++)
			{
				if(mp[i][j]<mp[i][g]+mp[g][j])
				{
					
				}
				mp[i][j]=min(mp[i][j],mp[i][g]+mp[g][j]);	
			}
		}
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=i+1;j<n;j++)
		{
			c+=mp[i][j];
		}
	}
	*/
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
