#include<bits/stdc++.h>
#define int long long
#define maxn 505
using namespace std;
const int mod=998244353;
int n,m,c[maxn],s[maxn];
inline int ksm(int d,int z){
	int res=1;
	while(z){
		if(z&1)res=(res*d)%mod;
		d=(d*d)%mod;z>>=1;
	}
	return res;
}
namespace SubtaskA{
	int dp[1<<18][20];
	vector<int>hav[20];
	inline void solve(){
		dp[0][0]=1;
		for(int S=0;S<(1ll<<n);++S)hav[__builtin_popcount(S)].push_back(S);
		for(int i=1;i<=n;++i){
			//µÚiÌì
			for(auto S:hav[i-1]){
				for(int j=1;j<=n;++j){
					if(S&(1ll<<(j-1)))continue;
					int T=S+(1ll<<(j-1)),now=s[i];
					for(int k=0;k<i;++k){
						int noi=now;
						if((i-1-k)>=c[j])noi=0;
						if(k+noi<=n){
							dp[T][k+noi]+=dp[S][k];
							dp[T][k+noi]=(dp[T][k+noi]%mod+mod)%mod;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;++i){
			ans+=dp[(1ll<<n)-1][i];
			ans=(ans%mod+mod)%mod;
		}
		cout<<ans;
		return;
	}
}
bool subtaskB=1;
namespace SubtaskB{
	int dp[2][maxn][maxn];
	inline void solve(){
		return;
	}
}
namespace SubtaskC{
	int dp[2][maxn][maxn],ans=1;
	int cnt,suf[maxn];
	inline void solve(){
		for(int i=1;i<=n;++i)++c[i];
		for(int i=1;i<=n;++i)ans=(ans*i)%mod;
		sort(c+1,c+1+n);reverse(c+1,c+1+n);
		for(int i=n;i>=1;--i)if(s[i]==0)++cnt;
		for(int i=n;i>=1;--i)suf[i]=suf[i+1]+s[i];
		dp[0][0][cnt]=1;
		for(int i=0;i<n;++i){
			int delta=suf[c[i+1]]-suf[c[i]];
			for(int j=0;j<=n;++j)for(int k=0;k<=cnt;++k)dp[(i+1)&1][j][k]=0;
			for(int j=0;j<=n;++j){
				int nxt=j+delta;
				for(int k=0;k<=cnt;++k){
					if(nxt>=1)
					dp[(i+1)&1][nxt-1][k]=(dp[(i+1)&1][nxt-1][k]+dp[i&1][j][k]*nxt)%mod;
					if(k>=1)
					dp[(i+1)&1][nxt][k-1]=(dp[(i+1)&1][nxt][k-1]+dp[i&1][j][k]*k)%mod;
				}
			}
		}
		ans=(ans+mod-dp[n&1][0][0])%mod; 
		ans=(ans+mod)%mod;cout<<ans;
		return;
	}
}
namespace SubtaskD{
	int dp[maxn][maxn],ans=1;
	inline void solve(){
		sort(c+1,c+1+n);
		for(int i=1;i<=n;++i){
			if(s[i]==0){
				cout<<0;
				return;
			}
		}
		dp[0][0]=1;
		for(int i=1;i<=n;++i)ans=(ans*i)%mod;
		for(int i=0;i<n;++i){
			int delta=c[i+1]-c[i];
			for(int j=0;j<=n;++j){
				int nxt=j+delta;
				if(nxt-1>=0&&nxt-1<=n)
					dp[i+1][nxt-1]=(dp[i+1][nxt-1]+dp[i][j]*nxt)%mod;
			}
		}
		ans=(ans-dp[n][0]+mod)%mod;
		cout<<(ans+mod)%mod;
		return;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;int tot=0;
	for(int i=1;i<=n;++i){
		char czs;cin>>czs;
		s[i]=(czs=='1');
		tot+=s[i];
		if(s[i]!=1)subtaskB=false;
	}
	if(tot<m){cout<<0;return 0;}
	for(int i=1;i<=n;++i)cin>>c[i];sort(c+1,c+1+n);
	if(n<=18){SubtaskA::solve();return 0;}
	if(m==1){SubtaskC::solve();return 0;}
	if(m==n){SubtaskD::solve();return 0;}
//	if(subtaskB){SubtaskB::solve();return 0;}
	int ans=1;for(int i=1;i<=n;++i)ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
