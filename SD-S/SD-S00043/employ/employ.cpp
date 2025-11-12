#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
 }
const int N=505,M=20;
const int mod=1e9+7;
int dp[300000][M],p[N],n,m,l[N],v[N],ls[300000][M];
char ch[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>ch;
	for(int i=1;i<=n;i++)p[i]=read();
	l[0]=1;
	for(int i=1;i<=30;i++)l[i]=l[i-1]*2;
	if(n<=18)
	{
		int sx=(1<<n)-1;
		dp[0][0]=1;
		for(int k=1;k<=n;k++)
		{
			for(int i=0;i<=sx;i++)for(int j=0;j<=n;j++)ls[i][j]=dp[i][j];
			for(int j=sx;j>=0;j--)
			{
				int kop=j,sum=0;
				for(int i=20;i>=0;i--)
				{
					if(kop>=l[i])
					{
						sum++;
						v[i]=1;
						kop-=l[i];
					}
					else v[i]=0;
				}
//				cout<<j<<" "<<sum<<'\n';
				if(sum!=k-1)continue;
//				cout<<k<<" "<<j<<'\n';
				for(int i=1;i<=n;i++)
				{
					if(v[i-1])continue;
					for(int o=k;o>=0;o--)
					{
						if(ch[k-1]=='0')dp[j+(1<<(i-1))][o]=(dp[j+(1<<(i-1))][o]+ls[j][o])%mod;//cout<<i<<" "<<o<<" "<<ls[j][o]<<'\n';
						else
						{
//					cout<<o<<'\n';
							if(k-o-1<p[i])dp[j+(1<<(i-1))][o+1]=(dp[j+(1<<(i-1))][o+1]+ls[j][o])%mod;
							else dp[j+(1<<(i-1))][o]=(dp[j+(1<<(i-1))][o]+ls[j][o])%mod;
						}
					}
				}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<=sx;j++)cout<<dp[j][i]<<' ';
//			cout<<'\n';
//		}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)ans=(ans+dp[sx][i])%mod;
		cout<<ans;
		return 0;
	}
	if(n==m)
	{
		for(int i=0;i<n;i++)
		{
			if(ch[i]=='0'||p[i+1]==0)
			{
				cout<<0;
				return 0; 
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{
			cout<<0;
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}

