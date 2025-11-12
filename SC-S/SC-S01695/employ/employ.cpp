#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define cmax(a,b) ((a)=max((a),(b)))
#define cmin(a,b) ((a)=min((a),(b)))
#define pb emplace_back
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,ans,c[N],dp[1<<18][19];
inline void add(int &x,int y){x+=y;x>=mod&&(x-=mod);}
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)cin>>c[i];
	if(n<=18){
		dp[0][0]=1;
		for(int k=1;k<(1<<n);++k){
			for(int j=0;j<n;++j){
				if(((k>>j)&1)==0)continue;
				int p=k^(1<<j),q=__builtin_popcount(p);
				for(int l=0;l<=q;++l){
					if(s[q]=='1'&&l<c[j+1])add(dp[k][l],dp[p][l]);
					else add(dp[k][l+1],dp[p][l]);
				}
			}		
		}
		for(int i=0;i<=n-m;++i)add(ans,dp[(1<<n)-1][i]);
		return cout<<ans,0;
	}
	if(m==n){
		for(int i=1;i<=n;++i)if(c[i]==0||s[i-1]==0)return cout<<0,0;
		int ans=1;
		for(int i=1;i<=n;++i)ans=ans*i%mod;
		return cout<<ans,0;
	}
	return 0;
}