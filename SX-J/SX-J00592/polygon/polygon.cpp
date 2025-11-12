#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,dp[5005],a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++) ans=(ans+dp[j])%P;
		for(int j=5001;j>=0;j--) dp[min(5001,j+a[i])]=(dp[min(5001,j+a[i])]+dp[j])%P;
	}
	printf("%d\n",ans);
	return 0;
}