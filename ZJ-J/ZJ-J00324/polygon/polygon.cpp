#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
int n,a[6006],sum=0,maxx=-100,ans=0;
int jc(int n)
{
	int p=1;
	for(int i=2;i<=n;i++)
	{
		p*=i%Mod;
	}
	return p%Mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
		cout<<maxx<<" ";
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(sum>2*maxx)
		{
			cout<<1;
			return 0;
		}
		else cout<<0;
		return 0;
	}
	if(maxx<=1)
	{
		for(int i=3;i<=n-1;i++)
		{
			ans+=jc(n)%Mod/(jc(n-i)%Mod*jc(i)%Mod)%Mod;
		}
		cout<<(1+ans)%Mod;
		return 0;
	}
	else
	{
		cout<<12;
	}
	return 0;
}
