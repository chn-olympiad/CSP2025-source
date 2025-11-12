#include<bits/stdc++.h>
using namespace std;
int n,k,d[1<<20],s[555555],p[555555],dp[555555];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(d,255,sizeof(d));
	for(int i=1;i<=n;i++){int x;scanf("%d",&x);s[i]=s[i-1]^x;}
	for(int i=n;i;i--){
		p[i+1]=d[s[i]];
		d[k^s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dp[p[i]]=max(dp[p[i]],dp[i-1]+1);
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%d",dp[n]);
}