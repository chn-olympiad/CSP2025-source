#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
char s[510];
int aa[510],mtp[510];
int c[510][510],a[510][510];
int num[510],sumn[510];
int f[2][510][510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j,k,ll,n,m,x,ans=0;
	scanf("%d%d%s",&n,&m,s+1);
	mtp[0]=1;
	for(i=1;i<=n;++i)
	{
		aa[i]=s[i]-'0';
		mtp[i]=1LL*mtp[i-1]*i%p;
		scanf("%d",&x);
		num[x]++;
	}
	for(i=0;i<=n;++i)
	{
		c[i][0]=a[i][0]=1;
		for(j=1;j<=i;++j)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
			a[i][j]=1LL*c[i][j]*mtp[j]%p;
		}
	}
	sumn[0]=num[0];
	for(i=1;i<=n;++i) sumn[i]=sumn[i-1]+num[i];
	f[0][0][0]=1;
	for(i=1;i<=n;++i)
	{
		for(j=0;j<=n;++j)
			for(k=0;k<=n;++k)
				f[i&1][j][k]=0;
		for(j=0;j<=i-1;++j)
			for(k=0;k<=i-1;++k)
				if(aa[i]==0)
				{
					for(ll=0;ll<=num[j+1];++ll)
					{
						if(k>=ll&&sumn[j]>=i-1-k)
						f[i&1][j+1][k-ll]=(f[i&1][j+1][k-ll]+1LL*f[i&1^1][j][k]*(sumn[j]-(i-1-k))%p*c[num[j+1]][ll]%p*a[k][ll]%p)%p;
						if(k+1>=ll)
						f[i&1][j+1][k+1-ll]=(f[i&1][j+1][k+1-ll]+1LL*f[i&1^1][j][k]*c[num[j+1]][ll]%p*a[k+1][ll]%p)%p;
					}
				}
				else
				{
					f[i&1][j][k+1]=(f[i&1][j][k+1]+f[i&1^1][j][k])%p;
					for(ll=0;ll<=num[j+1];++ll)
						if(k+1>=ll)
						f[i&1][j+1][k-ll]=(f[i&1][j+1][k-ll]+1LL*f[i&1^1][j][k]*(sumn[j]-(i-1-k))%p*c[num[j+1]][ll]%p*a[k][ll]%p)%p;
				}
	}
	for(j=0;j<=n-m;++j)
		ans=(ans+1LL*f[n&1][j][n-sumn[j]]*mtp[n-sumn[j]]%p)%p;
	printf("%d\n",ans);
	return 0;
}
