#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
inline int read()
{
	int s=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())f|=(c=='-');
	for(;isdigit(c);c=getchar())s=(s<<1)+(s<<3)+(c^48);
	return f?-s:s;
}
const int mod=998244353;
inline int qpow(int x,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=1ll*x*res%mod;
		x=1ll*x*x%mod;
		p>>=1;
	}
	return res;
}
const int N=507;
int n,m,ans,c[N],mul[N],fra[N],dp[N][N];
vector<int> v;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	bool flag=0;
	for(int i=0;i<n;i++)flag|=(s[i]=='0');
	if(!flag)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			c[i]=read(),tot+=(c[i]>0);
			if(c[i]>0)v.pb(c[i]);
		}
		if(tot<m)printf("0");
		else
		{
			dp[0][0]=1;
			for(int i=1;i<=tot;i++)
			{
				for(int j=0;j<=n-tot;j++)
				{
					if(i>m)
					{
						for(int k=0;k<=n-tot-j;k++)
						{
							dp[i][j+k]=(ll)(dp[i][j+k]+dp[i-1][j])%mod;
						}
					}else
					{
						for(int k=0;k<=v[i-1];k++)
						{
							dp[i][j+k]=(ll)(dp[i][j+k]+dp[i-1][j])%mod;
						}
					}
				}
			}
			//tot box->m box;n-tot ball
//			mul[0]=1;
//			for(int i=1;i<=n;i++)mul[i]=1ll*mul[i-1]*i%mod;
//			fra[n]=qpow(mul[n],mod-2);
//			for(int i=n-1;i>=0;i--)fra[i]=1ll*fra[i+1]*(i+1)%mod;
//			ans=1ll*mul[tot]*fra[tot-m]%mod*mul[n-m]%mod;
			printf("%d",dp[tot][n-tot]);
		}
	}else
	{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
