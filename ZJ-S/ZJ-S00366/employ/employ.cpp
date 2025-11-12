#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,m,s[510],a[510],c[510],fac[510],p[510],ans1,ans,b[510],f[2][1050000][20];
char ch;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ch,a[i]=ch-'0',s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]),ans1+=(c[i]==0);
	if(s[n]<m||n-ans1<m) {cout<<0;fclose(stdin);fclose(stdout);return 0;} 
	if(n==m)
	{
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		cout<<fac[n];fclose(stdin);fclose(stdout);return 0;
	}
	else if(n<=10)
	{
		for(int i=1;i<=n;i++) p[i]=i;
		do
		{
			int now=0;
			for(int i=1;i<=n;i++)
			{
				if(now>=c[p[i]]) now++;
				else if(a[i]==0) now++;
			}
			if(n-now>=m) ans++;
		}
		while(next_permutation(p+1,p+n+1));
		cout<<ans;
		fclose(stdin);fclose(stdout);return 0;
	}
//	else if(n<=18)
//	{
//		f[0][0][0]=1;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<(1<<n);j++)
//			{
//				int no=0;
//				for(int k=1;k<=n;k++) if(j&(1<<k-1)) no++; 
//				if(no!=i-1) continue;
//				for(int k=0;k<=i-1;k++)
//				  for(int l=1;l<=n;l++)
//				    if(!(j&(1<<l-1)))
//				      (f[i&1][j|(1<<l-1)][k+(c[l]<=k||a[i]==0)]+=f[(i&1)^1][j][k])%=mod;
//			}
//		}
//		for(int i=n;i>=n-m;i--) (ans+=f[n&1][(1<<n)-1][i])%=mod;
//		cout<<ans;  fclose(stdin);fclose(stdout);return 0;
//	}
	else if(m==1)
	{
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		cerr<<fac[n]<<endl;
		for(int i=1;i<=n;i++) b[c[i]]++;
		for(int i=1;i<=n;i++) b[i]+=b[i-1];
		cerr<<b[0]<<endl;
		long long ans2=1,t=0;
		for(int i=1;i<=n;i++) if(a[i]==1) (ans2*=(b[i-1]-t))%=mod,t++;
		cout<<((fac[n]-ans2*fac[n-t]%mod)%mod+mod%mod);fclose(stdin);fclose(stdout);return 0;
	}
	else if(s[n]==n&&ans1==0)
	{
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		cout<<fac[n];fclose(stdin);fclose(stdout);return 0;
	}
	else {cout<<0;fclose(stdin);fclose(stdout);return 0;}
}//24+
