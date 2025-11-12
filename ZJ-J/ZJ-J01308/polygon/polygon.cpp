#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int mod=998244353;
int a[5005],ans,o;
int n;
int fac(int a,int b)
{
	int x=1;
	for(int i=a;i>=a-b+1;i--)
	{
		x*=i;
		x/=(a-i+1);
		x%=mod;
	}
	return x;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],o+=a[i];
	if(n==3)
	{
		if(o>2*a[1]&&o>2*a[2]&&o>2*a[3])
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	else if(o==n)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=fac(n,i);
			ans%=mod;
		}
		cout<<(ans+mod-1)%mod<<endl;
	}
	return 0;
}
/*
It's so boring.
I don't know how to solve this problem.
I think [312,336]pts is enough for first prize.
Hopes for afternoon.
Rp++.
*/
