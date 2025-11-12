#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int a[N];
int dp[N][N*2];
int mod=998244353;
signed main(){
	//9:09 thought the O(n^3) solution,can got 80 pts
	//9:49 thought the O(n^2) solution,can got 100 pts
	//10:02 ACed the example
	//10:05 ACed the big example
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<2*N;j++){
				ans+=dp[i-1][j];
				ans%=mod;
			}
		}
		dp[i][a[i]]=1;
		for(int j=1;j<2*N;j++){
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
			dp[i][min(2*N-1,a[i]+j)]+=dp[i-1][j];
			dp[i][min(2*N-1,a[i]+j)]%=mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
