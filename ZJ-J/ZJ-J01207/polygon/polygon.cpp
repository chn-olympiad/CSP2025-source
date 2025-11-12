#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,z=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=3;j<=n;j++)
		{
			if(i>j||abs(i-j)+1<3)
			{
				continue;
			}
			int h=0,zd=-1;
			for(int k=i;k<=j;k++)
			{
				h+=a[k];
				zd=max(zd,a[k]);
			}
			if(h>2*zd)
			{
				z++;
				z%=998244353;
				for(int k=i+1;k<j;k++)
				{
					if(h-a[k]>2*zd&&abs(i-j)>=3)
					{
						z++;
						z%=998244353;
					}
				}
			}
		}
	}
	cout<<z;
	return 0;
}
