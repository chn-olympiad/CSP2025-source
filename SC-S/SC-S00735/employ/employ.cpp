#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=(1<<18)+10;
const ll mod=998244353;
int n,m,c[N];
char t[N];
ll f[2][M][20];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",t);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	f[0][0][0]=1;int len=(1<<n)-1;
	int v=0;
	for(int i=0;i<n;i++)
	{
		v=v^1;
		memset(f[v],0,sizeof(f[v]));
		for(int s=0;s<=len;s++)
		{
			for(int k=0;k<=i;k++)
			{
				for(int j=1;j<=n;j++)
				{
					if(s>>(j-1)&1) continue;
					if(i-k>=c[j]||t[i]=='0')
					{
						f[v][s+(1<<(j-1))][k]=(f[v][s+(1<<(j-1))][k]+f[v^1][s][k])%mod;
					}	
					else
					{
						f[v][s+(1<<(j-1))][k+1]=(f[v][s+(1<<(j-1))][k+1]+f[v^1][s][k])%mod;
					}
				}
			}	
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++) ans=(ans+f[v][len][i])%mod;
	printf("%lld",ans);
	return 0;
}