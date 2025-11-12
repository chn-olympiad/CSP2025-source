#include <bits/stdc++.h>
using namespace std;
int t,n,a[4][100005],b[100005],c[100005],d[4],o,p=999999;//a总 b最大 c最大下 d多少 
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			b[j]=-1;
		}
		for(int j=1;j<=3;j++)
		{
			d[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			
			for(int k=1;k<=3;k++)
			{
				cin>>a[k][j];
				if(b[j]<a[k][j])
				{
					b[j]=a[k][j];
					c[j]=k;
					
				}
			}
			ans+=b[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(c[j]==1)
			{
				d[1]++;
			}
			if(c[j]==2)
			{
				d[2]++;
			}
			if(c[j]==3)
			{
				d[3]++;
			}
		}
		if(d[1]<=n/2)
		{
			
		}
		else
		{
			o=d[1]-n/2;
			for(int j=1;j<=o;j++)
			{
				p=999999;
				for(int k=1;k<=n;k++)
				{
					if(c[k]==1)
					{
						if(p>a[1][k]-a[2][k])
						{
							p=a[1][k]-a[2][k];
							
						}
						if(p>a[1][k]-a[3][k])
						{
							p=a[1][k]-a[3][k];
						}
					}
				}
				for(int k=1;k<=n;k++)
				{
					if(c[k]==1)
					{
						if(p==a[1][k]-a[2][k])
						{
							c[k]=2;
							break;
						}
						if(p==a[1][k]-a[3][k])
						{
							c[k]=3;
							break;
						}
					}
				}
				ans-=p;
			}
		} 
		if(d[2]<=n/2)
		{
			
		}
		else
		{
			o=d[2]-n/2;
			for(int j=1;j<=o;j++)
			{
				p=999999;
				for(int k=1;k<=n;k++)
				{
					if(c[k]==2)
					{
						if(p>a[2][k]-a[1][k])
						{
							p=a[2][k]-a[1][k];
						}
						if(p>a[2][k]-a[3][k])
						{
							p=a[2][k]-a[3][k];
						}
					}
				}
				for(int k=1;k<=n;k++)
				{
					if(c[k]==2)
					{
						if(p==a[2][k]-a[1][k])
						{
							c[k]=1;
							break;
						}
						if(p==a[2][k]-a[3][k])
						{
							c[k]=3;
							break;
						}
					}
				}
				ans-=p;
			}
		}
		if(d[3]<=n/2)
		{
			
		}
		else
		{
			o=d[3]-n/2;
			for(int j=1;j<=o;j++)
			{
				p=999999;
				for(int k=1;k<=n;k++)
				{
					if(c[k]==3)
					{
						if(p>a[3][k]-a[2][k])
						{
							p=a[3][k]-a[2][k];
						}
						if(p>a[3][k]-a[1][k])
						{
							p=a[3][k]-a[1][k];
						}
					}
				}
				for(int k=1;k<=n;k++)
				{
					if(c[k]==3)
					{
						if(p==a[3][k]-a[2][k])
						{
							c[k]=2;
							break;
						}
						if(p==a[3][k]-a[1][k])
						{
							c[k]=1;
							break;
						}
					}
				}
				ans-=p;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
