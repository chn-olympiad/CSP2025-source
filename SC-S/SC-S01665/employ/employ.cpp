#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define R(i,x,y) for (int i=(x);i>=(y);i--)
using namespace std;

const int mod=998244353;
const int N=505;
int n,m,s[N],c[N],b[N],dp[N][N],nxt[N][N],bad[N],fct[N],inv[N];
inline void add (int &x,int y) {
	x=(x+y)%mod;
}
int qpow (int x,int y) {
	int a=1,u=x;
	while (y) {
		if (y&1) a=1ll*a*u%mod;
		u=1ll*u*u%mod;
		y>>=1;
	}
	return a;
}
int comb (int x,int y) {
	if (x<y||y<0) return 0;
	return 1ll*fct[x]*inv[y]%mod*inv[x-y]%mod;
}
int main () {
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	ios::sync_with_stdio (0); cin.tie (0);
	cin>>n>>m;
	fct[0]=1;
	F(i,1,n) fct[i]=1ll*fct[i-1]*i%mod;
	inv[n]=qpow (fct[n],mod-2);
	R(i,n-1,0) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	char tmp;
	F(i,1,n) {
		cin>>tmp;
		s[i]=tmp-'0';
	}
	F(i,1,n) bad[i]=bad[i-1]+1-s[i];
	F(i,1,n) cin>>c[i];
	F(i,1,n) ++b[c[i]];
	F(i,1,n) b[i]+=b[i-1];
	dp[0][0]=1;
	F(i,1,n) {
		F(j,0,n) {
			F(k,0,n) {
				if (!dp[j][k]) continue;
				// accept one
				if (s[i]) add(nxt[j][k+1],dp[j][k]);
				// decline one
				int base;
				if (s[i]) base=b[j]-(i-1-bad[i-1]-k);
				else base=1;
				if (base>0) {
					F(p,0,min(k,b[j+1]-b[j])) {
						add(nxt[j+1][k-p],1ll*dp[j][k]*base%mod*comb(b[j+1]-b[j],p)%mod);
						base=1ll*base*(k-p)%mod; 
					}
				}
			}
		}
		F(j,0,n) {
			F(k,0,n) {
				dp[j][k]=nxt[j][k];
				nxt[j][k]=0;
			}
		}
	}
	int ans=0;
	F(i,0,n-m) {
		F(j,0,n) {
			int res=dp[i][j];
			int r=n-b[i];
			if (r>=j) {
				F(k,1,j) {
					res=1ll*res*r%mod;
					--r; 
				}
				add (ans,res);
			}
			
		}
	}
	F(i,1,bad[n]) ans=1ll*ans*i%mod;
	cout<<ans<<"\n";
	return 0;
} 