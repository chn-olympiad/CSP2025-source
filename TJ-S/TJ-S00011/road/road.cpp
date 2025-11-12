#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct e
{
	long long v;
	int lu;
};
bool vol[10001];
long long w[8000][8000];
long long c[15][10001];
long long ans;
void djstl(int x)
{
	vol[x]=1;e d;d.v=9999999;
	for(int i=1;i<=n;i++)
	{
		if(vol[i]==0)
		{
			if(w[i][x]<d.v)
			{
				d.lu=i;
				d.v=w[i][x];
			}
		}
	}
	ans+=d.v;
	djstl(d.lu);
}
int main()
{
	freopen("road.in","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		long long v;
		cin>>v;
		w[a][b]=w[b][a]=v;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
		for(int d=1;d<=n;d++)
			for(int e=d+1;e<=n;e++)
			{
				if(w[d][e]!=0)
				{
					w[d][e]=w[e][d]=min(w[d][e],c[i][0]+c[i][d]+c[i][e]);
					if(c[i][0]!=0)
						ans+=c[i][0];c[i][0]=0;
				}
					
				else
				{
					w[d][e]=w[e][d]=c[i][d]+c[i][e];
					if(c[i][0]!=0)
						ans+=c[i][0];c[i][0]=0;
				}
					
			}
	}
	djstl(1);
	cout<<ans;
	freopen("road.out","w",stdout);
	return 0;

}

