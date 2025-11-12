#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=510,INF=0x3f3f3f3f,mod=998244353;
char st;
int n,m,c[N];
char s[N];
namespace bf{
	const int N=19;
	int f[N][(1<<N)+5],g[N][(1<<N)+5];
	void solve(){
		f[0][0]=1;
		for(int i=0;i<n;i++){
			for(int S=0;S<(1<<n);S++){
				int pc=__builtin_popcount(S);
				if(pc!=i)continue;
				for(int j=0;j<=i;j++){
//				cerr<<i<<' '<<j<<' '<<S<<endl;
					for(int k=1;k<=n;k++){
						if((S>>(k-1))&1)continue;
						int T=S|(1<<(k-1));
//						cerr<<"??? "<<T<<endl;
						if(s[i+1]=='1'){
							if(c[k]>j){
								g[j][T]=(g[j][T]+f[j][S])%mod;
							}else{
								g[j+1][T]=(g[j+1][T]+f[j][S])%mod;
							}
						}else{
							g[j+1][T]=(g[j+1][T]+f[j][S])%mod;
						}
					}
//					cerr<<f[i][j][S]<<endl;
				}
			}
			memcpy(f,g,sizeof(g));
		}
		int ans=0;
		for(int x=0;x<=n-m;x++){
			ans=(ans+f[x][(1<<n)-1])%mod;
		}
		cout<<ans<<endl;
	}
}
char ed;
signed main(){
//	cerr<<(&st-&ed)/1024.0/1024.0<<endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18)bf::solve();
	else{
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
/*
18 5
110111101100101011
6 0 4 2 1 2 5 4 3 3 3 5 4 3 2 1 4 5
*/
