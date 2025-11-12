#include<bits/stdc++.h>
using namespace std;
long long ans=0,mod=998244353;
long long a[5005],n;
long long A_C_A(int a,int b)
{
	long long ans_=1;
	for(int i=0;i<b;i++)
	{
		ans_*=(a-i);
	}
	return ans_;
}
long long A_C_C(int a,int b)
{
	if(a-b<b) return A_C_C(a,a-b);
	return A_C_A(a,b)/A_C_A(b,b);
}
void dfs(int dep,long long sum,long long maX,int num)
{
	if(dep>n)
	{
		if(sum>2*maX&&num>=3)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(dep+1,sum,maX,num);
	dfs(dep+1,sum+a[dep],max(maX,a[dep]),num+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag&&n>=30)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=A_C_C(n,i)%mod;
			ans=ans%mod;
		}
	}
	else
	{
		dfs(1,0,0,0);
	}
	cout << ans%mod;
	return 0;
}