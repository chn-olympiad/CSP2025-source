#include<bits/stdc++.h>
using namespace std;
const int mx=3e6+5;
int t,n,k,dp[mx],a[mx],tj[mx];
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int xz=0,ret=0;
	dp[0]=tj[0]=0;
	for(int i=1;i<=3e6;i++) tj[i]=-1e9;
	for(int i=1;i<=n;i++){
		xz^=a[i];
		dp[i]=max(dp[i-1],tj[xz^k]+1);
		tj[xz]=dp[i];
		ret=max(ret,dp[i]);
	}
	cout<<ret<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t=1;
	colse();
	while(t--) solve();
	return 0;
}