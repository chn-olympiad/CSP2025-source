//李倏嘉 SN-S00323 西安铁一中国际合作学校
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,Mod=998244353;
int n,m,fac[N],inv[N],num[N],sum[N],f[2][N][N],ans;
char s[N];
int ksm(int x,int y)
{
	int ret=1,bace=x;
	while(y)
	{
		if(y&1)ret=ret*bace%Mod;
		bace=bace*bace%Mod;
		y>>=1;
	}
	return ret;
}
int C(int n,int m)
{
	if(n<m)return 0;
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		num[x]++;
	}
	sum[0]=num[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+num[i];
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=i*fac[i-1]%Mod;
	inv[n]=ksm(fac[n],Mod-2);
	for(int i=n;i;i--)inv[i-1]=i*inv[i]%Mod;
	f[0][0][num[0]]=1;
	for(int i=0;i<n;i++)
	{
		memset(f[i+1&1],0,sizeof(f[i+1&1]));
		for(int j=0;j<=i;j++)
			for(int k=max(sum[j]-i,0ll);k<=sum[j];k++)
			{
				int tmp=f[i&1][j][k],tot=num[j+1],cnt=i-sum[j]+k;
				if(!tmp)continue;
				if(k)
				{
					for(int p=0;p<=min(tot,cnt);p++)
						f[i+1&1][j+1][k-1+tot-p]=(f[i+1&1][j+1][k-1+tot-p]+k*fac[tot]%Mod*inv[tot-p]%Mod*C(cnt,p)%Mod*tmp)%Mod;
				}
				if(s[i+1]=='0')
				{
					for(int p=0;p<=min(tot,cnt);p++)f[i+1&1][j+1][k+tot-p]=(f[i+1&1][j+1][k+tot-p]+fac[tot]%Mod*inv[tot-p]%Mod*C(cnt,p)%Mod*tmp)%Mod;
					for(int p=0;p<=min(tot-1,cnt);p++)f[i+1&1][j+1][k+tot-p-1]=(f[i+1&1][j+1][k+tot-p-1]+fac[tot]%Mod*inv[tot-p-1]%Mod*C(cnt,p)%Mod*tmp)%Mod;
				}
				else f[i+1&1][j][k]=(f[i+1&1][j][k]+tmp)%Mod;
			}
	}
	for(int i=0;i<=n-m;i++)ans=(ans+fac[n-sum[i]]*f[n&1][i][0])%Mod;
	printf("%lld",ans);
	return 0;
}

