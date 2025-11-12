#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5050,P=998244353;
int a[N],n,m;
ll dp[N][N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	m=a[n]+1;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+1;j<=m+1;++j){
			ans=(ans+dp[i-1][j])%P;
		}
		for(int j=0;j<=m+1;++j){
			dp[i][j]=(dp[i][j]+dp[i-1][j])%P;
			if(j+a[i]<=m)dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%P;
			else dp[i][m+1]=(dp[i][m+1]+dp[i-1][j])%P;
		}
	}
	printf("%lld",ans);
	return 0;
}

