#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f=1;
const int Mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(n==3)
	{
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])cout<<1;
		else cout<<0;
	}
	else if(f)
	{
		long long ans=0;
		long long aaa=1LL;
		for(int k=3;k<=n;k++)
		{
			if(k==3)
			{
				for(int i=n;i>n-k;i--)aaa*=i,aaa%=Mod;
				for(int i=k;i>=1;i--)aaa/=i;
			}
			else
			{
				aaa*=(n-k+1)%Mod;
				aaa%=Mod;
				aaa/=k;
			}
			ans+=(aaa%Mod);
			ans%=Mod;
		}
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
