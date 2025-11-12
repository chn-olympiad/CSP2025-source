#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ar[5009];
int dp[5009][5009];
int sum[5009];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> ar[i];
	}
	sort(ar+1,ar+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<ar[i];j++){
			dp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=ar[n];j++){
			dp[i][j]+=sum[max(0LL,j-ar[i])];
			dp[i][j]%=mod;
//			for(int k=0;k<i;k++){
//				dp[i][j]+=dp[k][max(0LL,j-ar[i])];
//				dp[i][j]%=mod;
//			}
//			sum[j]+=dp[i][j];
//			sum[j]%=mod;
		}
		for(int j=0;j<=ar[n];j++){
			sum[j]+=dp[i][j];
			sum[j]%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans+=dp[j][ar[i]];
			ans%=mod;
		}
	}
//	cout << endl;
	cout << ans;
	return 0;
}
/*
09:48 [0-300]pts
10:11 [0-368]pts
10:24 [0-400]pts
*/
