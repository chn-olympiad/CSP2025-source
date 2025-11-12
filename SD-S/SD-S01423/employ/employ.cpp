#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 505
#define Mod 998244353
using namespace std;
int read()
{
	int fl=1,x=0;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')fl=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*fl;
}
int n,m,num[N],f[300005][25];
char s[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)num[i]=read();
	if(n==m)
	{
		int Ans=1;
		for(int i=1;i<=n;i++)(Ans*=(s[i]-'0')*i*(num[i]!=0))%=Mod;
		cout<<Ans<<'\n';
		return 0;
	}
	if(n<=18)
	{
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int k=1;k<=n;k++)
				cnt+=((i>>(k-1))&1);
			for(int j=0;j<=n;j++)
			{
				if(f[i][j]==0)continue;
				for(int k=1;k<=n;k++)
				{
					if((i>>(k-1))&1)continue;
					if(num[k]<=j||s[cnt+1]=='0')(f[i|(1<<(k-1))][j+1]+=f[i][j])%=Mod;
					else (f[i|(1<<(k-1))][j]+=f[i][j])%=Mod;
				}
			}
		}
		int Ans=0;
		for(int i=0;i<=n-m;i++)
			Ans+=f[(1<<n)-1][i];
		cout<<Ans<<'\n';
		return 0;
	}
	return 0;
}
