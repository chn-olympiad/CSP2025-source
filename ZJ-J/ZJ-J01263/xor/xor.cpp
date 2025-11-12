#include <bits/stdc++.h>
using namespace std;

int n,a[500005],Sumxor[500005],k;
int dp[500005];
bool f[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Sumxor[i]=Sumxor[i-1]^a[i];
		if(a[i]==k)dp[i]=1;
	}
		
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(f[j])break;
			if((Sumxor[j-1]^Sumxor[i])==k and dp[i]<dp[j-1]+1){
				dp[i]=dp[j-1]+1;
				f[i]=true;
			}
		}
		
		dp[i]=max(dp[i],dp[i-1]);
	}
		
	printf("%d\n",dp[n]);
	return 0;
}
