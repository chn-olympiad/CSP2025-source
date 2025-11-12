//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int a[5050];
int dp[2][10010];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int d=0;
	dp[d][0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=10001;j>a[i];j--){
			ans=(ans+dp[d][j])%p;
		}
		for(int j=0;j<=10001;j++)dp[d^1][j]=dp[d][j];
		for(int j=0;j<=10001;j++){
			if(j+a[i]<=10000)dp[d^1][j+a[i]]=(dp[d^1][j+a[i]]+dp[d][j])%p;
			else dp[d^1][10001]=(dp[d^1][10001]+dp[d][j])%p;
		}
		d^=1;
	}
	printf("%d",ans);
	return 0;
}
