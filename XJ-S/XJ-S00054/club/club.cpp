#include<iostream>
using namespace std;
int a[100005][5],f[100005][5],g[100005],g1[100005],g2[100005];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int maxx=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				maxx=max(maxx,a[i][j]);
				if(maxx!=m)
				{
					m=maxx;
					f[i][j]=1;
				}
				else
				{
					f[i][j]=0;
				}
			}
			
		}
		int zd=n/2,my=0,minn=10005,minn1=10005,minn2=10005,ll=0,rr=0,ss=0;;
		for(int i=1;i<=n;i++)
		{
			if(f[i][1]==1)
			{
				g[i]=a[i][1];
				minn=min(minn,a[i][1]);
				ll++;
			}
			if(f[i][2]==1)
			{
				g1[i]=a[i][2];
				minn1=min(minn1,a[i][2]);
				rr++;
			}
			if(f[i][3]==1)
			{
				g2[i]=a[i][3];
				minn2=min(minn2,a[i][3]);
				ss++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(minn==a[i][1]&&ll>zd)
			{
				if(a[i][2]>a[i][3])
				{
					g1[i]=a[i][2];
				}
				else
				{
					g2[i]=a[i][3];
				}
				g[i]=0;
			}
			if(minn1==a[i][2]&&rr>zd)
			{
				if(a[i][1]>a[i][3])
				{
					g[i]=a[i][1];
				}
				else
				{
					g2[i]=a[i][3];
				}
				g1[i]=0;
			}
			if(minn2==a[i][3]&&ss>zd)
			{
				if(a[i][1]>a[i][2])
				{
					g[i]=a[i][1];
				}
				else
				{
					g2[i]=a[i][2];
				}
				g2[i]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			my+=g[i]+g1[i]+g2[i];
		}
		cout<<my<<" ";
	}
	return 0;
}
