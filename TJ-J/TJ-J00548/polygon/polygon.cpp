#include <bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005][5005][2],maxn,sum,maxm;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0][0]=1;
	dp[0][0][1]=1;
	for(int i=1;i<=n;i++){
		sum=0;
		maxn=0;
		for(int j=1;j<=n;j++){
			dp[maxn][j][0]=dp[maxn][j-1][0]+dp[maxn][j-1][1];
			if(2*(sum+a[j])>max(maxn,a[j])){
				dp[max(maxn,a[j])][j][1]=dp[maxn][j][0]+1;
				maxn=max(maxn,a[j]);
				sum+=a[j];
			}
			maxm=max(maxm,max(dp[maxn][j][1],dp[maxn][j][0]));
		}
	}
	cout<<maxm;
	return 0;
}
