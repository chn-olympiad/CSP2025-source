//SN-J00015 QIAOYUXIAO
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[100010],ans,num[45],tot;
long long zh[5010],jie[5010];
bool check(int ss)
{
	int ret=0,maxx=0;
	tot=0;
	for(int i=1;i<=40;i++)num[i]=0;
	int x=ss;
	while(x)
	{
		num[++tot]=x%2;
		x/=2;
	}
	for(int i=tot;i;i--)
	{
		if(num[i]==1)
		{
			ret+=a[i];
			maxx=max(maxx,a[i]);
		}
	}
	if(ret>2*maxx)return 1;
	else return 0;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>50)
	{
		jie[0]=1;
		for(int i=1;i<=n;i++)
		{
			jie[i]=(jie[i-1]*i)%mod;
			jie[i]%=mod;
		}
		for(int i=1;i<=n;i++)
		{
			zh[i]=(jie[n]/jie[i])%mod;
			zh[i]=(zh[i]/jie[n-i])%mod;
		}
		for(int i=3;i<=n;i++)
		{
			ans=(ans+zh[i])%mod;
		}
	}
	else
	{
		for(int i=1;i<=(1<<n)-1;i++)
		{
			if(check(i)==1)
			{
				ans=(ans+1)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
