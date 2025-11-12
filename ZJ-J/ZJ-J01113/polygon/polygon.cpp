#include<bits/stdc++.h>
using namespace std;
long long a[10010000],c[1001][1001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,n;
	for(i=0;i<=1000;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
	}
	for(i=2;i<=50;i++)
	{
		for(j=1;j<=i;j++)//Ñî»ÔÈý½ÇÔ¤´¦Àí 
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=998244353;
		}
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3)
	{
		if(n<3)
		{
			cout<<0;
			return 0;
		}
		if(n==3)
		{
			if(a[1]+a[2]>a[3])
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	else if(a[n]==1)
	{
		long long ans=0;
		for(i=3;i<=n;i++)
		{
			ans+=c[n][i];
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
