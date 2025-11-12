#include <bits/stdc++.h>
using namespace std;
long long n,v[5005],w[5005],a[5005],sum; 
long long dp[5005];
int main(){
	dp[0] = 1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i=1;i<=n;i++){
		v[i] = a[i],w[i] = a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=sum;j>=v[i];j--){
			dp[j] += dp[j-v[i]];
		}
	}
	long long ans = -1;
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[i]);
	} 
	cout << ans + 3 << endl;
	return 0;
}
