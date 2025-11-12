#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,x,a[1000],b[1000],c[1000],num=0,a1,b1,c1,a2[1000],b2[1000],c2[1000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=3*i-2*i;j<=x;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]>c[j]||a[j]>c[j]>b[j])
		    {
				num+=a[j];
				a1++;
			}
			else if(b[j]>a[j]>c[j]||b[j]>c[j]>a[j])
			{
				num+=b[j];
				b1++;
			}
			else if(c[j]>b[j]>a[j]||c[j]>a[j]>b[j])
			{
				num+=c[j];
				c1++;
			}
			
		}
		if(a1>n/2)
		{
			long long d;
			for(int j=1;j<=n;j++)
			{
				for(int t=1;t<=n;t++)
				{
					if(a[t]<a[j])
			    	{
						swap(a[t],a[j]);
					}
				}
			}
			d=a1-(n/2);
			for(int j=a1;j>=d;j--)
			{
				num-=a[j];
				if(b[j]>=c[j])
				{
					num+=b[j];
				}
				else
				{
					num+=c[j];
				}
			}
		}
		else if(b1>n/2)
		{
			long long d;
			for(int j=1;j<=n;j++)
			{
				for(int t=1;t<=n;t++)
				{
					if(b[t]<b[j])
			    	{
						swap(b[t],b[j]);
					}
				}
			}
			d=b1-(n/2);
			for(int j=b1;j>=d;j--)
			{
				num-=b[j];
				if(a[j]>=c[j])
				{
					num+=a[j];
				}
				else
				{
					num+=c[j];
				}
			}
		}
		else if(c1>n/2)
		{
			long long d;
			for(int j=1;j<=n;j++)
			{
				for(int t=1;t<=n;t++)
				{
					if(c[t]<c[j])
			    	{
						swap(c[t],c[j]);
					}
				}
			}
			d=c1-(n/2);
			for(int j=c1;j>=d;j--)
			{
				num-=c[j];
				if(b[j]>=a[j])
				{
					num+=b[j];
				}
				else
				{
					num+=a[j];
				}
			}
		}
		cout<<num;
	}
	return 0;
}
