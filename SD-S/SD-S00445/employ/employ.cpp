#include<bits/stdc++.h>
#define N 505
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[N],dp[2][1<<18][20],p[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;++i)cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;++i)p[i]=i;int ans=0;
		do{
			int qwq=0;
			for(int i=1;i<=n;++i)if(s[i]=='0'||qwq>=c[p[i]])++qwq;
			if(n-qwq>=m)++ans;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	else if(n<=18){
		dp[0][0][0]=1;
		for(int i=1;i<=n;++i){
			memset(dp[i&1],0,sizeof(dp[i&1]));
			for(int j=0;j<(1<<n);++j){
				for(int k=0;k<=n;++k){
					if(!dp[!(i&1)][j][k])continue;
					for(int l=1;l<=n;++l){
						if((j>>l-1)&1)continue;
						if(k>=c[l]||s[i]=='0')(dp[i&1][j|(1<<l-1)][k+1]+=dp[!(i&1)][j][k])%=mod;
						else (dp[i&1][j|(1<<l-1)][k]+=dp[!(i&1)][j][k])%=mod;
					}
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n-m;++j)ans=(ans+dp[n&1][(1<<n)-1][j])%mod;
		cout<<ans<<'\n';
	}
	return 0;
}

