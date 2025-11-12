#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define lep(i,l,r) for(int i=(l);i>=(r);--i)
#define int long long
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define fi first
#define se second

const int N=19;
const int mod=998244353;

int n,m;
char ch[N];
int c[N];

int f[N][N][1<<N];

void solver_008(){
	cin>>n>>m;
	cin>>(ch+1);
	rep(i,1,n)cin>>c[i];
	f[0][0][0]=1;
	rep(i,1,n){
		rep(s,0,(1<<n)-1)if(__builtin_popcount(s)==i-1){
			rep(j,0,i-1)rep(k,1,n)if(!(s&(1<<k-1))){
				int F=ch[i]=='1'&&(i-1-j)<c[k];
				(f[i][j+F][s|(1<<k-1)]+=f[i-1][j][s])%=mod;
			}
		}
	}
	int ans=0;
	rep(i,m,n)ans=(ans+f[n][i][(1<<n)-1])%mod;
	cout<<ans;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __T=1;
	while(__T--){
		solver_008();
	}
	return 0;
}
