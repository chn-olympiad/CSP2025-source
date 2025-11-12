#include<bits/stdc++.h>
using namespace std;
const int N=1.1e6;
int n;
long long k,a[N],pre[N],dp[N][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		for(int j=1;j<=i;j++){
			long long flag=0;
			if((pre[i]^pre[j-1+dp[j][1]])==k)flag=1;
			if(dp[j][0]+flag>dp[i][0]){
				dp[i][0]=dp[j][0]+flag;
				break;
			}
		}
		if(dp[i][0]!=dp[i-1][0])dp[i][1]=1;
	}
	printf("%d",dp[n][0]);
	return 0;
}
