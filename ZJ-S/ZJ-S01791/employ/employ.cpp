#include<bits/stdc++.h>
using namespace std;
const int N=18,mod=998244353;
int n,m,c[N],f[1<<N][20],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<n;++i){
		scanf("%d",&c[i]);
	}
	f[0][0]=1;
	for(int S=0;S<(1<<n);++S){
		int g=__builtin_popcount(S);
		for(int i=0;i<n;++i){
			if(S&(1<<i)){
				continue;
			}
			for(int j=0;j<=n;++j){
				if(g-j<c[i]&&s[g]=='1'){
					f[S|(1<<i)][j+1]=(f[S|(1<<i)][j+1]+f[S][j])%mod;
				}
				else{
					f[S|(1<<i)][j]=(f[S|(1<<i)][j]+f[S][j])%mod;
				}
			}
		}
	}
	for(int i=m;i<=n;++i){
		ans=(ans+f[(1<<n)-1][i])%mod;
	}
	printf("%d",ans);
	return 0;
}