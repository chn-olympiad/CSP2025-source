#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,dp[100005];
struct S{
	ll a,b,c;
}arr[100005];
ll dfs(ll x, ll sum, ll cnta, ll cntb, ll cntc){
	printf("%lld %lld %lld %lld\n",cnta,cntb,cntc,sum);
	if(x==n+1) return sum;
	if(cnta>=n/2&&cntb<n/2&&cntc<n/2) dp[x] = max(dfs(x+1,sum+arr[x].b,cnta,cntb+1,cntc),dfs(x+1,sum+arr[x].c,cnta,cntb,cntc+1));
	if(cntb>=n/2&&cnta<n/2&&cntc<n/2) dp[x] = max(dfs(x+1,sum+arr[x].a,cnta+1,cntb,cntc),dfs(x+1,sum+arr[x].c,cnta,cntb,cntc+1));
	if(cntc>=n/2&&cntb<n/2&&cnta<n/2) dp[x] = max(dfs(x+1,sum+arr[x].a,cnta+1,cntb,cntc),dfs(x+1,sum+arr[x].b,cnta,cntb+1,cntc));
	if(cnta>=n/2&&cntb<n/2&&cntc>=n/2) dp[x] = dfs(x+1,sum+arr[x].b,cnta,cntb+1,cntc);
	if(cnta>=n/2&&cntb>=n/2&&cntc<n/2) dp[x] = dfs(x+1,sum+arr[x].c,cnta,cntb,cntc+1);
	if(cnta<n/2&&cntb>=n/2&&cntc>=n/2) dp[x] = dfs(x+1,sum+arr[x].a,cnta+1,cntb,cntc);
	dp[x] = max(dfs(x+1,sum+arr[x].a,cnta+1,cntb,cntc),max(dfs(x+1,sum+arr[x].b,cnta,cntb+1,cntc),dfs(x+1,sum+arr[x].c,cnta,cntb,cntc+1)));
	return dp[x];
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i = 1; i <= n; i++)
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
		printf("%lld\n",dfs(1,0,0,0,0));
	}
	return 0;
} 
