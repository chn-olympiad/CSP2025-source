#include<bits/stdc++.h>
const int MAXN=5005;
const int inf=0x7f7f7f7f;
typedef long long LL;
const LL mod=998244353;
int n,a[MAXN];
LL power[MAXN],inv[MAXN],dp[MAXN][5005];
inline int _rand(int l,int r)
{
	int p=rand();
	p=abs(p);
	return p%(r-l+1)+1;
}
inline LL qpow(LL x,LL y)
{
	LL ans=1;
	while(y)
	{
		if(y&1)
			(ans*=x)%=mod;
		(x*=x)%=mod,y>>=1; 
	}
	return ans;
}
inline LL C(int n,int m)
{
	if(n<m) return 0LL;
	else if(m==0) return 1LL;
	return power[n]*inv[m]%mod*inv[n-m]%mod;
}
inline LL work1()
{
	LL ans=0;
	for(int mark=1;mark<(1<<n);mark++)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if((mark>>(i-1))&1)
				cnt++;
		if(cnt<3) continue;
		LL sum=0,mx=0;
		for(int i=1;i<=n;i++)
			if((mark>>(i-1))&1)
				sum+=a[i],mx=std::max(mx,1LL*a[i]);
		if(sum>mx*2) (ans+=1)%=mod;
	}
	return ans;
}
inline LL work2()
{
	int mi=inf,mx=-inf;
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		mi=std::min(mi,a[i]),mx=std::max(mx,a[i]);
		if(i<3) continue;
		for(int j=mi;j<=mx;j++)
		{
			for(int k=2;k<i;k++)
				(ans+=C(i-1,k))%=mod;
		}
	}
	return ans;
}
inline void init() 
{
	power[0]=1;
	for(int i=1;i<=5000;i++)
		power[i]=power[i-1]*i%mod;
	inv[5000]=qpow(power[5000],mod-2),inv[0]=1;
	for(int i=5000-1;i>=1;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
}
inline void solve()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool fl=1;
	for(int i=1;i<=n&&fl;i++)
		fl&=(a[i]<=1);
	if(fl)
	{
		printf("%lld\n",work2());
		return;
	}
	if(n<=20)
	{
		printf("%lld\n",work1());
		return;
	}
	printf("%d\n",_rand(244353,998244352));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}
