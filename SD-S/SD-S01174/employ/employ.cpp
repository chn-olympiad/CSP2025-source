#include<bits/stdc++.h>
using namespace std;
#define il inline
#define getbit(x,y) (((x)>>(y))&1)
#define lowbit(x) ((x)&(-x))
#define mkp make_pair
#define fi first
#define se second
#define N 505
#define mod 998244353
#define popcnt __builtin_popcount
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
typedef unsigned uint;
il ll read() {
	ll x=0;bool f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=0;c=getchar();}
	while(isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?x:-x;
}
int n,m;
int c[N];
char s[N];
namespace Sub_bf {
	ll dp[1<<18][19];
	il void solve() {
		dp[0][0]=1;
		for(int S=0;S<(1<<n)-1;++S) {
			int k=popcnt(S);
			for(int i=0;i<=k;++i) {
				if(!dp[S][i]) continue;
				for(int j=1;j<=n;++j) {
					if(getbit(S,j-1)) continue;
					int res=0;
					if(c[j]<=i||s[k+1]=='0') res=1;
					(dp[S^(1<<(j-1))][i+res]+=dp[S][i])%=mod;
				}
			}
		}
		ll sum=0,U=(1<<n)-1;
		for(int i=0;i<=n-m;++i) (sum+=dp[U][i])%=mod;
		printf("%lld\n",sum);
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) c[i]=read();
	if(n<=18) return Sub_bf::solve(),0;
	return 0;
}

