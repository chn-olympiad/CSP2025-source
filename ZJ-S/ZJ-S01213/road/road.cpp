#include<bits/stdc++.h>
using namespace std;
struct youhavenoeggs
{
	int u,v,w;
}a[1000005];
int n,m,k,f[10005],b[15][10005],c[15];
long long s;
int cmp(youhavenoeggs x,youhavenoeggs y)
{
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0)
	{
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			cout<<a[i].u<<" "<<a[i].v<<endl;
			if(f[a[i].u]==0 && f[a[i].v]==0)
			{
				f[a[i].u]=f[a[i].v]=a[i].u;
				s=s+a[i].w;
			}
			else if(f[a[i].u]!=f[a[i].v])
			{
				s=s+a[i].w;
				if(f[a[i].v]==0)
				{
					f[a[i].v]=f[a[i].u];
					continue;
				}
				if(f[a[i].u]==0)
				{
					f[a[i].u]=a[i].u;
					for(int j=1;j<=n;j++)
					{
						if(f[j]==f[a[i].v])
						{
							f[j]=f[a[i].u];
						}
					}
					continue;	
				}
				for(int j=1;j<=n;j++)
				{
					if(f[j]==f[a[i].v])
					{
						f[j]=f[a[i].u];
					}
				}
			}
		}
		cout<<s;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>b[i][j];
			}
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			cout<<a[i].u<<" "<<a[i].v<<endl;
			if(f[a[i].u]==0 && f[a[i].v]==0)
			{
				f[a[i].u]=f[a[i].v]=a[i].u;
				s=s+a[i].w;
			}
			else if(f[a[i].u]!=f[a[i].v])
			{
				for(int j=1;j<=k;j++)
				{
					if(b[j][a[i].u]+b[j][a[i].v]<a[i].w)
					{
						s=s-a[i].w+b[j][a[i].u]+b[j][a[i].v];
						break;
					}
				}
				s=s+a[i].w;
				if(f[a[i].v]==0)
				{
					f[a[i].v]=f[a[i].u];
					continue;
				}
				if(f[a[i].u]==0)
				{
					f[a[i].u]=a[i].u;
					for(int j=1;j<=n;j++)
					{
						if(f[j]==f[a[i].v])
						{
							f[j]=f[a[i].u];
						}
					}
					continue;	
				}
				for(int j=1;j<=n;j++)
				{
					if(f[j]==f[a[i].v])
					{
						f[j]=f[a[i].u];
					}
				}
			}
		}
		cout<<s;
	}
	return 0;
}
