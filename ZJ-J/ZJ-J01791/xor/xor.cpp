#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],xor1[N],xor2[N],dp[N],s,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i),s^=a[i];
	if(n<=10000){
		for(int i=1;i<=n;i++) xor1[i]=xor1[i-1]^a[i];
		for(int i=n;i>=1;i--) xor2[i]=xor2[i+1]^a[i];
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=1;j<=i;j++){
				int x=s^xor1[j-1]^xor2[i+1];
				if(x!=k) continue;
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}printf("%d",dp[n]);
		return 0;
	}
	for(int i=1;i<=n;i++) if(a[i]==k) ans++;
	printf("%d",ans);
	return 0;
}

