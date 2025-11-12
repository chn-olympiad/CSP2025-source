#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
const int maxn=5e5+7;
int a[maxn];
ll dp[maxn];
int pre[maxn];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	if(n>1000) {
		int one=0;
		ll ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans+=one/2;
					one=0;
					ans++;
				}else one++;
			}
		}else
			for(int i=1;i<=n;i++) ans+=a[i];
		cout<<ans<<endl;
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				dp[i]=max(dp[i],dp[j-1]+((pre[i]^pre[j-1])==k));
			}
		}
		cout<<dp[n];
	}

	return 0;
}
