#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int s[20],c[18],popcount[1<<18],f[1<<18][18];
int n,m,ans;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char a;
		cin>>a;
		s[i]=a^'0';
	}
	for(int i=0;i<n;++i) cin>>c[i];
	for(int i=1;i<1<<n;++i){
		popcount[i]=popcount[i^(i&(-i))]+1;
	}
	f[0][0]=1;
	for(int u=1;u<1<<n;++u){
		for(int i=0;i<n;++i){//now choose i
			if(u>>i&1){
				int v=u^(1<<i);
				for(int j=0;j<=popcount[v];++j){
					if(!s[popcount[u]]){
						f[u][j+1]=(f[u][j+1]+f[v][j])%M;	
					}else{
						if(j>=c[i]) f[u][j+1]=(f[u][j+1]+f[v][j]);
						else f[u][j]=(f[u][j]+f[v][j])%M;
					}
				}
			}
		}
	}
	for(int i=m;i<=n;++i) ans=(ans+f[(1<<n)-1][n-i])%M;
	cout<<ans;
	return 0;
}
