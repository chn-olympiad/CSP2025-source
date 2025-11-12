#include<bits/stdc++.h>
//#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define mid ((l+r)>>1)
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int n,a[N];
long long dp[2][N*2];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(a[i],maxn);
	sort(a+1,a+n+1);
	int x=1,y=0;
	dp[0][0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=2*maxn+1;j>=0;j--)dp[x][j]=dp[y][j];
		for(int j=2*maxn+1;j>=0;j--){
			int nj=min(2*maxn+1,j+a[i]);
			if(!dp[y][j])continue;
			dp[x][nj]=(dp[x][nj]+dp[y][j])%mod;
		}
		for(int j=a[i]*2+1;j<=maxn*2+1;j++)
			ans=(ans+(dp[x][j]-dp[y][j]+mod)%mod)%mod; 
		swap(x,y);
	}
	cout<<ans<<endl;
	return 0;
}
