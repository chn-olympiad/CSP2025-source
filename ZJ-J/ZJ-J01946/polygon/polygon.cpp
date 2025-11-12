#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int P=998244353;
const int N=5010;
int n,ans,a[N],s[N];
int dp[2][N];
void dfs(int x,int sum,int mx){
	if(sum>mx*2){
		++ans;
		if(ans>=P) ans-=P;
//		return ;
	}
	if(x>n)return ;
//	if(mx*2>=s[n])return ;
	for(int i=x;i<=n;i++)
		dfs(i+1,sum+a[i],a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;++i)
//		s[i]=s[i-1]+a[i];
//	if(n<=20){
		dfs(1,0,0);
		printf("%d",ans);
		return 0;
//	}
//	dp[1][a[1]]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%P;
//		for(int j=0;j<=5000;j++)
//			h=(h+dp[h+1][i+1])%P;
//	}
//	dp[1][a[1]]=1;
//	for(int i=2;i<=n;i++){
//		for(int j=a[i]+1;j<=5001;j++){
//			dp[i][j]=(dp[i][j]+dp[i-1][j])%P;
//		}
//		for(int j=0;j<=5000;j++)
//			dp[i][min(5001,j+a[i])]++;
//	}
//	int c=1;
//	for(int i=1;i<=n;i++){
//		c^=1;
//		memset(dp[c],0,sizeof(dp[c]));
//		for(int j=1;j<=n;j++)
//			dp[c][j]=(dp[c^1][j-1]+dp[c^1][j])%P;
//		for(int j=1;j<=n;j++){
//			
//		}
//	}
	return 0;
}
