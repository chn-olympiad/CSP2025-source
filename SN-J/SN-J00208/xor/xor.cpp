#include<iostream>
using namespace std;
constexpr int N=5e5+3,K=(1<<20)+5;
int n,k,a[N],sum[N],dp[N],ans,jntm[K];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<K;i++)jntm[i]=-1;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum[i]=sum[i-1]^a[i];
	jntm[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(jntm[sum[i]^k]+1,dp[i-1]);
		jntm[sum[i]]=max(jntm[sum[i]],dp[i]);
		ans=max(ans,dp[i]);
	}cout<<ans<<'\n';
	return 0;
}
