#include<bits/stdc++.h>
using namespace std;
int f[10020][10020],a[15][10020],dis[10020],c[15];
bool b[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool bl=0;
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1000000010;
	for(int i=1;i<=n;i++)
		dis[i]=1000000010;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	dis[1]=0;
			if(k==0)
						{
							for(int i=1;i<=n;i++)
							{
								int kk=0,minn=1000000010;
								for(int j=1;j<=n;j++)
									if(!b[j]&&dis[j]<minn)
										kk=j,minn=dis[j];
								if(kk==0)  break;
								b[kk]=1;
								for(int j=1;j<=n;j++)//1-k-j
									if(!b[j])
										dis[j]=min(dis[j],f[kk][j]);
							}
							int ans=0;
							for(int i=1;i<=n;i++)
								ans+=dis[i];
							cout<<ans<<endl;
							return 0;
						}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int kk=0,minn=1000000010;
		for(int j=1;j<=n;j++)
			if(!b[j]&&dis[j]<minn)
				kk=j,minn=dis[j];
		if(kk==0)  break;
		b[kk]=1;
		for(int j=1;j<=n;j++)//1-kk-j
			if(!b[j])
			{
				for(int cou=1;cou<=k;cou++)
				{
					if(c[cou]==0)
					{
						if(a[cou][kk]+a[cou][j]<=min(dis[j],f[kk][j]))
							dis[j]=a[cou][kk]+a[cou][j],a[cou][kk]=a[cou][j]=0,ans+=dis[j];
						else
							if(f[kk][j]<=dis[j])
								dis[j]=f[kk][j],ans+=dis[j],f[kk][j]=0;
						else
							dis[j]=dis[j];
					}
					else
					{
						if(a[cou][kk]+a[cou][j]+c[cou]<=min(dis[j],f[kk][j]))
							dis[j]=a[cou][kk]+a[cou][j],c[cou]=a[cou][kk]=a[cou][j]=0,ans+=c[cou],ans+=dis[j];
						else
							if(f[kk][j]<=dis[j])
								dis[j]=f[kk][j],ans+=dis[j],f[kk][j]=0;
						else
							dis[j]=dis[j];
					}
				}
			}
	}
	cout<<ans<<endl;
	return 0;
 } 
