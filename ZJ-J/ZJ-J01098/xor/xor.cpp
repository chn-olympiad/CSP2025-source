#include<bits/stdc++.h>
using namespace std;
int yihuo(long long a,long long b)
{
	int x[30]={0},y[30]={0},z[30]={0};
	long long l=0,r=0,c=0;
	while(a!=0||b!=0)
	{
		if(a!=0)
		{
			x[++l]=a%2;
			a/=2;
		}
		if(b!=0)
		{
			y[++r]=b%2;
			b/=2;
		}
	}
	for(int ss=max(l,r);ss>=1;ss--)
	{
		if(x[ss]==y[ss])
		{
			z[ss]=0;
		}
		else
		{
			z[ss]=1;
		}
		c=c*2+z[ss];
	}
	return c;
}
long long n,m,x,y,k,a[500010],f[500010],q,s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s=0;
		for(int j=i;j<=n;j++)
		{
			s=yihuo(s,a[j]);
			if(s==k)
			{
				for(int aa=j;aa>=1;aa--)
				{
					if(f[aa]!=0)
					{
						f[j]=f[aa];
						break;
					}
				}
				for(int aa=i;aa>=1;aa--)
				{
					if(f[aa]!=0)
					{
						f[i]=f[aa];
						break;
					}
				}
				f[j]=max(f[i]+1,f[j]);
				break;
			}
		}
	}
	while(f[n]==0)
	{
		n--;
	}
	cout<<f[n];
	return 0;
}
