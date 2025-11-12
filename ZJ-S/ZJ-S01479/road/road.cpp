#include<bits/stdc++.h>
using namespace std;
struct tt
{
	int zd,w;
};
vector<tt>a[10001];
int c[11];
int p[11][10001];
bool di[11];
bool bj[10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y,z;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		tt xx;
		xx.zd=y;
		xx.w=z;
		a[x].push_back(xx);
		xx.zd=x;
		a[y].push_back(xx);
	}
	int zq=n;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		n++;
		for(int j=1;j<=zq;j++)
		{
			cin>>p[i][j];
			m++;
			tt xx;
			xx.zd=j;
			xx.w=p[i][j];
			a[n].push_back(xx);
			xx.zd=n;
			a[j].push_back(xx);
		}
	}
	int ans=0;
	bj[1]=true;
	for(int i=1;i<n;i++)
	{
		int mi=INT_MAX;
		int zd=0;
		for(int j=1;j<=n;j++)
		{
			if(bj[j])
			{
				for(int k=0;k<a[j].size();k++)
				{
					tt xx=a[j][k];
					if(!bj[xx.zd])
					{
						if(xx.w<mi)
						{
							mi=xx.w;
							zd=xx.zd;
						}
					}
				}
			}
		}
		bj[zd]=true;
		ans+=mi;
	}
	cout<<ans<<endl;
	return 0;
}
