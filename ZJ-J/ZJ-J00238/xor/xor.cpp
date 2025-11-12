#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=5e5+5;
int n,k,a[N],pre[N],dp[N],l[N];
bool l1[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	l1[0]=1;
	for(ri i=1;i<=n;++i){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i];
		dp[i]=dp[i-1];
		if(a[i]==k) dp[i]=dp[i-1]+1;
		else if(l1[pre[i]^k]){
			dp[i]=max(dp[i],dp[l[pre[i]^k]]+1);
		}
		l[pre[i]]=i;
		l1[pre[i]]=1;
	}
	printf("%d",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}