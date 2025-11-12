#include<bits/stdc++.h>
using namespace std;
const int Mode = 998244353;
const int N = 5e3+5;
int a[N];
int dp[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+(n+1));
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = a[n]; j >= 0; j--){
			dp[i][j] = dp[i-1][j];
			if(j >= a[i]){
				dp[i][j] = (dp[i-1][j-a[i]]+dp[i][j])%Mode;
			}
			else{
				dp[i][j] = (dp[i][j]+1+dp[i-1][0])%Mode;
			}
		}
	}
	for(int i = 3; i <= n; i++){
		ans = (ans+dp[i-1][a[i]])%Mode;
	}
	cout << ans;
	return 0;
}
