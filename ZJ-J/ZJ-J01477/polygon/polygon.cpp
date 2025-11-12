#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,mod=998244353;
long long jc[maxn],ny[maxn],q[maxn];
int n,ans,a[maxn],f[maxn],mx;
long long ks(long long a,int b)
{
	long long r=1;
	while(b)
	  {
	  	if(b&1)
	  	  r=(r*a)%mod;
	  	a=(a*a)%mod;
		b=b>>1;
	  }
	return r;
}
long long C(int n,int m)
{
	return ((jc[n]*ny[m])%mod*ny[n-m])%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	jc[0]=1;
	ny[0]=1;
	for(int i=1;i<=5e3;i++)
	  jc[i]=(jc[i-1]*i)%mod,ny[i]=ks(jc[i],mod-2);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]),mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=mx;j>=0;j--)
	  	  if(f[j])
	  	    {
	  	    	if(j+a[i]<=mx)
	  	    	  f[j+a[i]]=(f[j+a[i]]+f[j])%mod;
			}
	  }
	for(int i=1;i<=n;i++)
	  f[a[i]]--;
	for(int i=1;i<=mx;i++)
	  q[i]=(q[i-1]+f[i])%mod; 
	for(int i=3;i<=n;i++)
	  ans=(ans+C(n,i))%mod;
	for(int i=1;i<=n;i++)
	  ans=(ans-q[a[i]]+mod)%mod;
	printf("%d",(ans+mod)%mod);
	return 0;
}
