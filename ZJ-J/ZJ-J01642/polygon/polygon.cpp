#include<bits/stdc++.h>
using namespace std;
const int N=5005,Mod=998244353;
long long n,ans,a[N],dp[N][N],C[N][N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j) C[i][j]=C[i-1][j]+C[i-1][j-1],C[i][j]%=Mod;
	}
	for(int i=3;i<=n;++i) ans+=C[n][i],ans%=Mod;
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	for(int j=0;j<N;++j)
	{
		dp[i][j]=dp[i-1][j];
		if(j>=a[i]) dp[i][j]+=dp[i-1][j-a[i]];
		dp[i][j]%=Mod;
	}
	for(int i=3;i<=n;++i)
	{
		ans+=i;
		for(int j=0;j<=a[i];++j) ans-=dp[i-1][j],ans%=Mod;
	}
	cout<<(ans%Mod+Mod)%Mod;
	return 0;
}
