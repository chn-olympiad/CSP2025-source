#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans,cnt,num,s[5005],fl=1,mod=998244353;
void dfs(int k,int sum,int t,int f)
{
	if(t>=2&&sum!=0&&f)
	{
		cnt=lower_bound(a+1,a+1+n,sum)-a;
		if(cnt>k)
			ans=(ans+cnt-k)%mod;
	}
	if(k==n)	return ;
	dfs(k+1,sum+a[k],t+1,1);
	dfs(k+1,sum,t,0);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)	fl=0;
	}
//	if(fl)
//	{
//		for(int i=3;i<=n;i++)
//		{
//			
//		}
//		return 0;
//	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)
//	{
//		s[i]=s[i-1]+a[i];
//	}
	dfs(1,0,0,0);
//	for(int i=3;i<=n;i++)
//	{
//		for(int j=i-1;j<n;j++)
//		{
//			num=s[j]-s[j-i+1];
//			cnt=lower_bound(a+1,a+1+n,num)-a;
//			ans+=cnt-1-j;
//		}
//	}
	cout<<ans;
	return 0;
}