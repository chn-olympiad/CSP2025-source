#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 110, mod = 998244353;
int f[N][N][N], cnt[N], w[N], fac[N], inv[N];
char s[N];
int A(int a, int b){return fac[a]*inv[a-b]%mod;}
int C(int a, int b){return fac[a]*inv[b]%mod*inv[a-b]%mod;}
void Add(int &a, int b){a=(a+b)%mod;}

int power(int a, int b)
{
	int c = 1;
	while(b)
	{
		if(b&1) c = c * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return c;
}

signed main()
{
	freopen("employ.in","r",stdin);
	// freopen("employ.out","w",stdout);
	int n, m, i, j, k, x, a, ans = 0;
	for(i=fac[0]=1;i<=N-10;i++) fac[i] = fac[i-1] * i % mod;
	for(i=N-11,inv[N-10]=power(fac[N-10],mod-2);i>=0;i--) inv[i] = inv[i+1] * (i + 1) % mod;
	// assert(inv[0]==1);
	scanf("%lld%lld%s", &n, &m, s+1);
	for(i=1;i<=n;i++) scanf("%lld", &a), cnt[a]++;
	w[0] = cnt[0];
	for(i=1;i<=n;i++) w[i] = w[i-1] + cnt[i];
	f[0][0][cnt[0]] = 1;
	for(i=0;i<n;i++) for(j=0;j<=i;j++) for(k=0;k<=n;k++) if(f[i][j][k])
	{
		if(s[i+1]=='1')
		{
			f[i+1][j][k] = (f[i+1][j][k] + f[i][j][k]) % mod;
			for(x=0;x<=i-(w[j]-k)&&x<=cnt[j+1];x++) Add(f[i+1][j+1][k+cnt[j+1]-x-1],f[i][j][k]*k%mod*A(i-(w[j]-k),x)%mod*C(cnt[j+1],x)%mod);
		}
		else
		{
			for(x=0;x<=i-(w[j]-k)&&x<=cnt[j+1];x++) Add(f[i+1][j+1][k+cnt[j+1]-x-1],f[i][j][k]*k%mod*A(i-(w[j]-k),x)%mod*C(cnt[j+1],x)%mod);
			for(x=1;x<=i-(w[j]-k)+1&&x<=cnt[j+1];x++) Add(f[i+1][j+1][k+cnt[j+1]-x],f[i][j][k]*C(i-(w[j]-k),x-1)%mod*C(cnt[j+1],x)%mod*fac[x]%mod);
			for(x=0;x<=i-(w[j]-k)&&x<=cnt[j+1];x++) Add(f[i+1][j+1][k+cnt[j+1]-x],f[i][j][k]*A(i-(w[j]-k),x)%mod*C(cnt[j+1],x)%mod);
		}
	}
	// printf("%lldd\n", f[1][0][0]);
	// printf("%lldd\n", f[2][1][0]);
	for(i=0;i<=n-m;i++) ans = (ans + f[n][i][0] * fac[n-w[i]]) % mod;
	printf("%lld\n", ans);
	return 0;
}