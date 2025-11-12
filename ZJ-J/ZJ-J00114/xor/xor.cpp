#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,q,ans;
int a[maxn],dp[maxn];
int sum[maxn];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1; i<=n; i++) {
		int f=0;
		dp[i]=dp[i-1];
		for(int j=i-1;!f&&j>=0; j--) {
			if(dp[j]+1<=dp[i-1]){
				break;
			}
			if((sum[i]^sum[j])==k) {
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
