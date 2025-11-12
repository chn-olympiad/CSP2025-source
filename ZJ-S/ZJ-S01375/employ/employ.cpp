#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c=getchar();int x=0;bool f=0;
	while(c>'9'||c<'0'){
		if(c=='-')f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(f)return -x;
	return x;
}
const int mod=998244353;
int n,m,a[505],dp[270005][20],siz[270005];
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		siz[i]=siz[i>>1]+(i&1);
		for(int j=0;j<=n;j++){
			for(int k=1;k<=n;k++){
				if((1<<k-1)&i)continue;
				int l=siz[i]-j;	
				if(l<0)continue;
				if(l>=a[k]||s[siz[i]+1]=='0')dp[i|(1<<k-1)][j]=(dp[i|(1<<k-1)][j]+dp[i][j])%mod;
				else dp[i|(1<<k-1)][j+1]=(dp[i|(1<<k-1)][j+1]+dp[i][j])%mod;
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)ans=(ans+dp[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}
