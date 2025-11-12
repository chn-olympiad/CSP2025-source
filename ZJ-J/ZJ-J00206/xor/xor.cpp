#include<bits/stdc++.h>
using namespace std;

inline int fastReadXor(){
	int s=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9'){f=(f||c=='-');c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}
int n,k;
int a[500005];
int s[500005];
int dp[500005];
int f[2999999];
int ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=fastReadXor();k=fastReadXor();
	for(int i=1;i<=n;i++){
		a[i]=fastReadXor();s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		f[s[i-1]]=i;
		if(f[k^s[i]]){
			int j=f[k^s[i]];
			dp[i]=max(dp[i],dp[j-1]+1);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}


