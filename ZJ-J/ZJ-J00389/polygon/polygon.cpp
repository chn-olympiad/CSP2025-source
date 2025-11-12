#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,num[5050],ans;
void fun(int lop,int cnt,int p,int sum)
{
	if(cnt>lop)
	{
		if(sum>2*num[p])
			ans=(ans+1)%mod;
		return;
	}
	for(int i=p+1;i<=n;i++)
		fun(lop,cnt+1,i,sum+num[i]);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	if(n==3)
	{
		if(num[3]>=num[1]+num[2])
			cout<<0;
		else
			cout<<1;
		return 0;
	}
	else if(n<=20)
	{
		for(int l=3;l<=n;l++)
			fun(l,1,0,0);
		cout<<ans;
	}
	else
	{
		int tmp=n*(n-1)*(n-2);
		int p=6;
		ans+=(tmp/p)%mod;
		tmp%=mod;
		for(int i=3;i<n;i++)
		{
			p=p*(i+1);p%=mod;
			tmp=tmp*(n-i);tmp%=mod;
			ans+=(tmp/p)%mod;
			ans%=mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
