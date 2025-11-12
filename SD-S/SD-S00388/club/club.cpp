#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+10;
ll t,n,ans,dp[210][210][210],a[N][3],b[N];
bool flag1,flag2;
void solve(){
	scanf("%lld",&n);
	flag1=flag2=true;
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][2])flag1=false;
		if(a[i][3])flag2=false;
	}
	if(n<=200){
		for(ll i=0;i<=n+1;i++){
			for(ll j=0;j<=n+1;j++){
				for(ll k=0;k<=n+1;k++){
					dp[i][j][k]=0;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<=i&&j<=n/2;j++){
				for(ll k=0;k+j<=i&&k<=n/2;k++){
					if(i-j-k>n/2)continue;
					if(i-j-k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				}
			}
		}
		ans=0;
		for(ll i=0;i<=n/2;i++){
			for(ll j=0;j<=n/2;j++){
			    ans=max(ans,dp[n][i][j]);	
			}
		}
		printf("%lld\n",ans);
	}
	else if(flag1&&flag2){
		for(ll i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b+1,b+n+1);
		ans=0;
		for(ll i=n;i>=n/2+1;i--){
			ans+=b[i];
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)solve();
	return 0;
} 
