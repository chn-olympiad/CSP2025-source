#include <bits/stdc++.h>
using namespace std;
int dp[500050];
int main() {
	std::ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	std::cin>>n>>k;
	std::vector<int> a(n);
	bool f=true;
	std::vector<int> xsum(n);
	for(int i=0; i<n; i++) {
		std::cin>>a[i];
		if(a[i]>1) {
			f=false;
		}
		if(i==0) {
			xsum[i]=a[i];
		} else {
			xsum[i]=xsum[i-1]^a[i];
		}
	}
	if(f) {
		if(k>1) {
			std::cout<<0;
		} else if(f==1) {
			int ans=0;
			for(int i=0; i<n; i++) {
				if(a[i]) {
					ans+=1;
				}
			}
			std::cout<<ans;
		} else {
			int ans=0;
			for(int i=0; i<n; i++) {
				if(!a[i]) {
					ans+=1;
				}
			}
			std::cout<<ans;
		}
		return 0;
	}
	if(a[0]==k) {
		dp[0]=1;
	} else {
		dp[0]=0;
	}
	for(int i=1; i<n; i++) {
		dp[i]=max(dp[i],dp[i-1]);
		int r=xsum[i]^0;
		if(r==k) {
			dp[i]=max(dp[i],dp[0]+1);
		}
		for(int j=0; j<i; j++) {
			int x=xsum[i]^xsum[j];
			if(x==k) {
				//std::cout<<i<<" "<<j<<'\n';
				dp[i]=max(dp[i],dp[j]+1);
				//std::cout<<dp[i]<<" ";
			}
		}
	}
	int ans=INT_MIN;;
	for(int i=0; i<n; i++) {
		ans=max(ans,dp[i]);
		//std::cout<<dp[i]<<" ";
	}
	std::cout<<ans;
	return 0;
}
