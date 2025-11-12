#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lf double
ll n,t,a[200005][3],dp[3][100005],c[3];
void solve();
int main() {
	freopen("club.in","r",stdin); //记得改！
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
		solve();
	return 0;
}
void solve() {
	memset(dp,0,sizeof dp);
	scanf("%lld",&n);
	for(ll i=1; i<=n; i++)
		for(ll j=0; j<3; j++)
			scanf("%lld",a[i]+j);
	for(ll i=1; i<=n; i++)
		for(ll j=0; j<3; j++)
			for(ll k=n/2; k>=1; k--)
				dp[j][k]=max(dp[j][k],max(dp[0][k-1],max(dp[1][k-1],dp[2][k-1]))+a[i][j]);
	printf("%lld\n",max(max(dp[0][n/2],dp[1][n/2]),dp[2][n/2]));
}
/* 连这个都不会该怎么办
  [||||]    佛祖 
   \__/   
   /  \   
  /    \  
 /______\  
 */
