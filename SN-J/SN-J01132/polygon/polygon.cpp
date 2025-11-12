#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[5050],dp[5050],ldp[5050];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1); 
	dp[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=mx+1;j++) ldp[j]=dp[j];
		for(int j=a[i]+1;j<=mx+1;j++) ans=(ans+dp[j])%mod;
		for(int j=0;j<=mx+1;j++) dp[min(mx+1ll,j+a[i])]=(dp[min(mx+1ll,j+a[i])]+ldp[j])%mod;
	}
	cout<<ans;
	return 0;	
}


















/*
会了哈哈
额啊啊啊啊啊
还有三个小时我干啥啊
带的东西吃完了 
不能野餐了 
难受 
好唐的题，怎么比我还唐
平衡粉笔序列立大功！ 
*/
