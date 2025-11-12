#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
long long get;
long long n;
long long k;
long long check(int num){
	if(num>n){
		return 0;
	}
	long long maxn=0;
	long long now;
	for(int i=num;i<=n;i++){
		if(dp[num][i]==k){
			now=check(i+1);
			if(now>maxn){
				maxn=now;
			}
		}
	}
	return maxn+1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>dp[i][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]^dp[j][j];
		}
	}
	cout<<check(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4