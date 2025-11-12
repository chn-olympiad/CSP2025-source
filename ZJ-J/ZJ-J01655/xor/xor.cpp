#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]^x);
	}
	vector<int>dp(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if((a[i]^a[j])==k){
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}
