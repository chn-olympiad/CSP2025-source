#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5003],wsr;
long long ans,tmp,t,k;
bool f=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
			f=0;
	}
	if(f)
	{
		ans=0;
		for(int i=3;i<=n;i++)
		{
			tmp=1;
			for(int j=n;j>n-i;j--)
				tmp=(tmp*j)%mod;
			ans+=tmp;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		for(long long j=3;j<(1<<(i-1));j++)
		{
			k=j,wsr=0;
			while(k)
			{
				wsr+=k%2;
				k>>=1;
			}
			if(wsr<2)
				continue;
			tmp=0;
			k=j;
			for(int l=1;l<=i;l++)
			{
				if(k%2==1)
				{
					tmp+=a[l];
				}
				k>>=1;
			}
			if(tmp>a[i])
				ans++;
		}
	cout<<ans%mod;
	return 0;
}
