#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssssss=s;freopen((ssssss+".in").c_str(),"r",stdin);freopen((ssssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define pb push_back
#define inl inline
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define mt(x,y) memset(x,y,sizeof x)
#define INF 1e18
#define ui unsigned
#define prr make_pair
using namespace std;
const int N=25,M=(1ll<<18)+5,MOD=998244353;
string s;
int c[N],f[M][N];
signed main(){
	fp("employ");
	fst;
	int n,m,ans=0;
	cin>>n>>m>>s;
	s=' '+s;
	rep(i,1,n) cin>>c[i];
	if(n==m){
		bool flag=1;
		rep(i,1,n) flag&=s[i]=='1';
		if(flag){
			int fc=1;
			rep(i,1,n) (fc*=i)%=MOD;
			cout<<fc<<endl;
		}else cout<<0<<endl;
		return 0;
	}
	f[0][0]=1;
	rep(i,1,(1ll<<n)-1)
		rep(j,1,n)
			if(i>>j-1&1)
				rep(k,0,(int)__builtin_popcount(i)-1)
					if(k<c[j]&&s[__builtin_popcount(i)]=='1') (f[i][k]+=f[i^1ll<<j-1][k])%=MOD;
					else (f[i][k+1]+=f[i^1ll<<j-1][k])%=MOD;
	rep(i,0,n-m) (ans+=f[(1ll<<n)-1][i])%=MOD;
	cout<<ans<<endl;
	return 0;
} 
