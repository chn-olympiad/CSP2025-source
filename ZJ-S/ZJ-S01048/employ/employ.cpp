#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read(){ ll x; scanf("%lld",&x); return x; }

const int mod = 998244353;

int n,m,c[505],qz[505]; char s[505];

int f[505][505][505], C[505][505], fac[505];
inline void addmod(int &x){ (x>=mod) && (x-=mod); }

void procedure(){
	n=read(),m=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[read()]++;

	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ull*fac[i-1]*i%mod;

	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) addmod(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	}

	qz[0]=c[0];
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+c[i];

	f[0][0][0]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<i;j++) for(int k=0;k<i;k++){
			if(!f[i-1][j][k]) continue;

			if(i>n) continue;
			// solved
			int q = qz[j] - (i-1-k);
			if(q<0) continue;

			if(s[i]=='1'){
				addmod(f[i][j][k+1] += f[i-1][j][k]);
				for(int w=0;w<=c[j+1] && w<=k;w++)
					f[i][j+1][k-w] = (f[i][j+1][k-w] + 1ull * f[i-1][j][k] * C[k][w] % mod * C[c[j+1]][w] % mod * fac[w] % mod * q) % mod;
			}else{
				for(int w=0;w<=c[j+1] && w<=k;w++){
					f[i][j+1][k-w] = (f[i][j+1][k-w] + 1ull * f[i-1][j][k] * C[k][w] % mod * C[c[j+1]][w] % mod * fac[w] % mod * q) % mod;
				}
				for(int w=0;w<=c[j+1] && w<=k; w++){
					f[i][j+1][k-w+1] = (f[i][j+1][k-w+1] + 1ull * f[i-1][j][k] * C[k][w] % mod * C[c[j+1]][w] % mod * fac[w]) % mod;
				}
				for(int w=0;w<c[j+1] && w<=k;w++){
					f[i][j+1][k-w] = (f[i][j+1][k-w] + 1ull * f[i-1][j][k] * C[k][w] % mod * C[c[j+1]][w+1] % mod * (w+1) % mod * fac[w]) % mod;
				}
			}
		}
	}

	int ans = 0;
	for(int i=0;i<=n-m;i++){
		int ok = 0;
		for(int j=i+1;j<=n;j++) ok += c[j];

		ans = (ans + 1ull * f[n][i][ok] * fac[ok]) % mod;
	}
	printf("%d\n", ans);
}
int main(){
	assert(freopen("employ.in","r",stdin));
	assert(freopen("employ.out","w",stdout));
	ll T=1;
	while(T--) procedure();
}