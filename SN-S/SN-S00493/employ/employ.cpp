//SN-S00493 PR++ 47 GXYZ
#include<cstdio>
#include<string>
#include<iostream>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],cnt1,cnt2;
ll fac,f[262200][19];
string s;
inline int get(int x)
{
	int res=0;
	while(x)
	{
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	fac=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]==0) cnt1++;
		if(s[i-1]=='0') cnt2++;
		fac=fac*i%mod;
	}
	if(n<=18)
	{
		f[0][0]=1;
		int tmp=(1<<n)-1;
		for(int st=0;st<=tmp;st++)
		{
			int x=get(st);
			for(int i=0;i<=x;i++)
			{
				if(!f[st][i]) continue;
				for(int j=1;j<=n;j++)
				{
					if(st&(1<<(j-1))) continue;
					int t=st|(1<<(j-1));
					int v=i;
					if(c[j]>x-i&&s[x]=='1') v++;
					f[t][v]=(f[t][v]+f[st][i])%mod;
				}
			}
		}
		ll ans=0;
		for(int i=m;i<=n;i++) ans=(ans+f[tmp][i])%mod;
		printf("%lld",ans);
		return 0;
	}
	if(n==m)
	{
		if(cnt1||cnt2) printf("0");
		else printf("%lld",fac);
		return 0;
	}
	if(m+cnt1>n||m+cnt2>n) printf("0");
	else printf("%lld",fac);
	return 0;
}
