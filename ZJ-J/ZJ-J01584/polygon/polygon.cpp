#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,ans,f=1;
long long a[5005],zh[5005][5005];
void init()
{
	for(int i=1;i<=n+3;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1||j==i)zh[i][j]=1;
			else zh[i][j]=(zh[i-1][j]+zh[i-1][j-1])%mod;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f)
	{
		for(int i=3;i<=n;i++)
		{
			ans=(ans+zh[n+1][i+1])%mod;
		}
		cout<<ans%mod;
	}
	else
	{
		for(int i=0;i<(1<<n);i++)
		{
			long long maxn=0,sum=0,x=0;
			for(int j=0;j<30;j++)
			{
				if(i&(1<<j))
				{
					x++;
					sum+=a[j+1];
					maxn=max(maxn,a[j+1]);
				}
			}
			if(x<3)continue;
			if(sum>maxn*2)ans=(ans+1)%mod;
		}
		cout<<ans;
	}
	return 0;
}