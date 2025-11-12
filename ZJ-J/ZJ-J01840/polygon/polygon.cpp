#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5005;
const int mod=998244353;
int a[maxn];
ll dp[50005];
ll gqh[maxn];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	gqh[0]=1;
	for(int i=1;i<=n;i++) gqh[i]=gqh[i-1]*2,gqh[i]%=mod;
	int Max=0;
	for(int i=1;i<=n;i++) cin>>a[i],Max=max(Max,a[i]);
	Max*=2;
	sort(a+1,a+1+n);
	ll ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		//choose ai
		int mx=a[i]*2;
		for(int j=mx+1-a[i];j<=Max*2;j++)
		{
			int u=j+a[i];
			if(u>Max) continue;
		//	cerr<<i<<" "<<j<<" "<<dp[j]<<" ts\n";
			ans+=dp[j],ans%=mod;
		}
		//j+ai>=mx+1
		//j>=mx+1-ai
		for(int j=Max*2;j>=1;j--)
		{
			if(j>=a[i]) dp[j]=dp[j]+dp[j-a[i]],dp[j]%=mod;
			else dp[j]=dp[j];
		//	cerr<<i<<" "<<j<<" "<<dp[j]<<"\n";
		}
		//if(i<n)
		for(int j=Max+1;j<=Max*2;j++)
		{
			ans+=dp[j]*gqh[n-i]%mod;
			ans%=mod;
			dp[j]=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//11:09 pretest passed(5)