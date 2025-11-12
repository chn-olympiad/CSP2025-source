#include<iostream>
#include<algorithm>
#define  int  long long
using namespace std;
constexpr int N=5005,p=998244353;
int n,a[N],w,dp[N][4],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1),w=a[n];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=a[i]+1;j<=w+1;j++)x=(x+dp[j][2])%p;
		ans=(ans+x)%p;
		for(int j=3;j>=2;j--){
			x=0;
			for(int k=w+1-a[i];k<=w+1;k++)x=(x+dp[k][j-1])%p;
			dp[w+1][j]=(dp[w+1][j]+x)%p;
			for(int k=w;k>=a[i];k--)dp[k][j]=(dp[k][j]+dp[k-a[i]][j-1])%p;
		}dp[a[i]][1]++;
		for(int j=0;j<=w+1;j++)dp[j][2]=(dp[j][2]+dp[j][3])%p,dp[j][3]=0;
	}cout<<ans<<'\n';
	return 0;
}
