#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=505,mod=998244353;
int n,m,c[M];
char s[M];
namespace pts8{
	int p[20];
	inline void main(){
		int ans=0;
		for(int i=0;i<n;++i)p[i]=i;
		do {
			int ok=0,cnt=0;
			for(int i=0;i<n;++i){
				if(cnt>=c[p[i]]||s[i]=='0')cnt++;
				else ok++;
			} ans+=(ok>=m);
		} while(next_permutation(p,p+n));
		printf("%lld",ans);
	}
}
namespace pts20{
	const int M=20,K=262150;
	signed f[M][K][M];
	#define rep(i,j) for(int i=0;i<(j);++i)
	inline void main(){
		int S=1<<n,ans=0;
		f[0][0][0]=1;
		rep(i,n){
			rep(j,S) rep(k,n) if(!(j&(1<<k))) rep(ok,i+1){
				int cnt=i-ok;
				if(cnt>=c[k]||s[i]=='0')
					(f[i+1][j|(1<<k)][ok]+=f[i][j][ok])%=mod;
				else (f[i+1][j|(1<<k)][ok+1]+=f[i][j][ok])%=mod;
			}
		}
		for(int j=m;j<=n;++j)
			(ans+=f[n][S-1][j])%=mod;
		printf("%lld",ans);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s);
	for(int i=0;i<n;++i)
		scanf("%lld",c+i);

	if(n<=10)pts8::main();
	else if(n<=18)pts20::main();
	else if(m==1){
		int res=1,cnt=0;
		for(int i=0;i<n;++i)
			if(s[i]=='1')(res*=(++cnt))%=mod;
		if(!cnt)res=0;
		printf("%lld",res);
	} else puts("0");
	return 0;
}
// 17:15 employ1~2.in/ans 20pts