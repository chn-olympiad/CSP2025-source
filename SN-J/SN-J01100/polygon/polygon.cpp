#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5025],mod=998244353,dp[50025],ans,cnt,sum;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0]=1;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=3) {
		if(n==3) {
			if(a[1]+a[2]>a[3]) {
				cout<<1;
			} else {
				cout<<0;
			}
		} else {
			cout<<0;
		}
	} else if(n<=500) {
		for(int i=n; i>0; i--) {
			memset(dp,0,sizeof(dp));
			dp[0]=1;
			for(int j=1; j<i; j++) {
				for(int k=50000; k>=a[j]; k--) {
					dp[k]+=dp[k-a[j]];
				}
			}
			for(int k=a[i]+1; k<=50000; k++) {
				ans+=dp[k];
				ans%=mod;
			}
		}
		cout<<ans;
	} else if(a[n]==1) {
		for(int j=1; j<=n; j++) {
			for(int k=5000; k>0; k--) {
				dp[k]+=dp[k-1];
			}
		}
		for(int k=5000; k>2; k--) {
			ans+=dp[k];
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
