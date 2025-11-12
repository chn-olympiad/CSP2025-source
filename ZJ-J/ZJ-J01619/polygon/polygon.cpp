#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n,a[maxn],ans,c[maxn][maxn],sum[maxn],d[maxn],dp[maxn][maxn],k,mx;
void solve(int m)
{
	int cnt=m-2;k=0;
	memset(dp,0,sizeof dp);
	for(int i=1;i<m;i++) d[i]=a[i];
	for(int i=0;i<m;i++) dp[i][0]=sum[i];
	for(int i=1;i<m;i++)
	for(int j=1;j<=a[m]+1;j++)
	 dp[i][j]=(dp[i-1][j]+dp[i-1][max(0ll,j-d[i])])%mod;
	//cout<<dp[k][a[m]+1]<<"\n"; 
	ans=(dp[m-1][a[m]+1]+ans)%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;c[0][0]=1;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
	 {
	 	//cnt++;
	 	if(i+j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		sum[i]+=c[i][j];
	 } 
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	if(mx==1)
	 {
	 	int ans=0;
	 	for(int i=3;i<=n;i++) ans=(ans+c[n][i])%mod;
		cout<<ans;return 0; 
	 }
	 
	sort(a+1,a+n+1);//cnt+=n*10;
	for(int i=3;i<=n;i++) solve(i);
	//cout<<cnt<<"\n";
	cout<<ans;
	return 0;
}
