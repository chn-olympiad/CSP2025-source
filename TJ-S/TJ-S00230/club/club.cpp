#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,ans=0,v[100000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m,b[100000],c[100000],d[100000],b1[100000],c1[100000],d1[100000],b2[100000],c2[100000],d2[100000];
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>b[j]>>c[j]>>d[j];
			v[i]=max(b[j],c[j],d[j]);
		}
		for(int l=1;l<=m;l++)
		{
			int g=-1;
			int g1=-1;
			int g2=-1;
			for(int q=1;q<=m;q++)
			{
				if(b[q]>g)
				{
					g=b[q];
					b2[l]=q;
				 } 
				 if(c[q]>g1)
				{
					g1=c[q];
					c2[l]=q;
				 } 
				 if(d[q]>g)
				{
					g2=d[q];
					d2[l]=q;
				 } 
			}
			b1[l]=g;
			c1[l]=g1;
			d1[l]=g2;
		}
			for(int t=1;t<=m;t++)
			{
				ans+max(b1[t],c1[t],d1[t]);
			}
		for(int j=1;j<=m;j++)
		{
			ans+=v[j];
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
