#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool mbs;
const int maxn=520;
const int maxm=(1<<18)+20;
#define ll long long
const int mod=998244353;
ll n,m,c[maxn];
char S[maxn];
namespace subtask1{
	ll dp[maxm][20],ans;
	inline void solve(){
		dp[0][0]=1;
		for(int s=1;s<(1<<n);s++){
			for(int i=1;i<=n;i++){
				if((s>>(i-1))&1){
					int t=(s^(1<<(i-1))),lim=__builtin_popcount(t);
					for(int j=0;j<=lim;j++){
						if(j>=c[i]||S[lim+1]=='0') dp[s][j+1]=(dp[t][j]+dp[s][j+1])%mod;
						else dp[s][j]=(dp[t][j]+dp[s][j])%mod;
//						cout<<t<<" "<<j<<" "<<dp[t][j]<<'\n';
					}
				}
			}
		}
		for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
		printf("%lld\n",ans);
	}
}
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>(S+1);
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=18) subtask1::solve();
	return 0;
}
/*
3 2
101
1 1 2
*/