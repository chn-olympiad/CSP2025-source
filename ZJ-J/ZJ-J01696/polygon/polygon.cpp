#include<bits/stdc++.h>
using namespace std;
int n,a[5555],dp[5555][5555],P=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=5001;j++){
			dp[i][min(j+a[i],5001)]=(dp[i-1][j]+dp[i][min(j+a[i],5001)])%P;
			dp[i][j]=(dp[i][j]+dp[i-1][j])%P;
		}
	}
	int ans=0;
	for(int i=2;i<n;i++){
		for(int j=a[i+1]+1;j<=5001;j++)ans=(ans+dp[i][j])%P;
	}
	printf("%d",ans);
}
