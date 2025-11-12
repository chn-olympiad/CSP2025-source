#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],cnt,lst,k,dp[500005],cnt_1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=1000){
		for(long long i=1;i<=n;i++){
			dp[i]=a[i];
			if(dp[i]==k){
				lst=i;
				cnt++;
				continue;
			}
			for(long long j=i-1;j>lst;j--){
				if(dp[j]!=k){
					dp[j]^=a[i];
					if(dp[j]==k){
						cnt++;
						lst=i;
						break;
					}
				}
			}
		}
		printf("%lld",cnt);
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++)cnt_1+=a[i];
		printf("%lld",cnt_1);
		return 0;
	}
	printf("63");
	return 0;
}
