#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N=505,mod=998244353;
int n,m;string s;
int c[N],g[N],dp[(1<<18)+5][20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;
	up(i,1,n) cin>>c[i],g[i]=s[i-1]-'0';
	int cnt=0;up(i,1,n) cnt+=g[i];
	if(m==n){
		ll ans=1;up(i,1,n) if(s[i]==0) ans=0;
		up(i,1,n) ans=1ll*ans*i%mod;printf("%lld\n",ans);
		return 0; 
	}
	else if(n==cnt){
		ll ans=1;up(i,1,n) ans=1ll*ans*i%mod;
		printf("%lld\n",ans);
		return 0; 
	}
	else if(n<=18){
		dp[0][0]=1;ll ans=0;
		up(i,0,(1<<n)-1){
			ll p=0;up(j,1,n) if(i&(1<<(j-1))) p++;
			up(j,1,n){
				if(i&(1<<(j-1))) continue;
				up(k,0,p){
					if(g[p+1]&&c[j]>p-k) dp[i|(1<<(j-1))][k+1]=(dp[i|(1<<(j-1))][k+1]+dp[i][k])%mod;
					else dp[i|(1<<(j-1))][k]=(dp[i|(1<<(j-1))][k]+dp[i][k])%mod;
				}
			}
		}
		up(k,m,n) ans=(ans+dp[(1<<n)-1][k])%mod;
		printf("%lld\n",ans);
	}
	else{
		ll ans=1;up(i,1,n) ans=1ll*ans*i%mod;
		printf("%lld\n",ans);
		return 0; 
	}
	return 0;
}