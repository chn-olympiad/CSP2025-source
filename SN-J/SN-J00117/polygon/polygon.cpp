//SN-J00117 ΑυκΕ³½ 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000;
const int MOD=998244353;
int n;
int a[MAXN+5];
//int dp[MAXN+5][4][MAXN+5];
//int sum[MAXN+5];
int ans=0;
void dfs(int sum,int mx,int cnt,int now){
	if(cnt>=3 && sum>2*mx){
		ans++;
		ans%=MOD;
	}
	for(int i=now;i<=n;i++){
		dfs(sum+a[i],max(mx,a[i]),cnt+1,i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,1);
//	sort(a+1,a+n+1);
//	dp[2][0][0]=1;
//	for(int i=0;i<a[1];i++) dp[2][0][i]++,dp[2][1][i]++;
//	for(int i=0;i<a[2];i++) dp[2][0][i]++,dp[2][1][i]++;
//	for(int i=0;i<a[1]+a[2];i++) dp[2][0][i]++,dp[2][1][i]++,dp[2][2][i]++;
//	for(int i=3;i<n;i++){
//		for(int j=1;j<=sum[i+1];j++){
//			dp[i][2][j]+=dp[i-1][1][j-a[i]];
//			dp[i][2][j]+=dp[i-1][2][j];
//			dp[i][1][j]+=dp[i-1][0][j-a[i]];
//			dp[i][1][j]+=dp[i-1][1][j];
//			dp[i][0][j]+=dp[i-1][0][j];
//		}
//	}
//	for(int i=2;i<=n-1;i++){
//		ans+=dp[i][2][a[i+1]];
//		cout<<"dp["<<i<<"][2][a["<<i+1<<"]]="<<dp[i][2][a[i+1]]<<' ';
//	}cout<<endl;
	printf("%d",ans);
	return 0;
}

