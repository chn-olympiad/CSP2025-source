#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int X=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=X*10+(ch-'0'); ch=getchar();}
	return X*f;
}
const int mod=998244353;
int n,m,k,tot,ans,a[5005];
char s[5005];
long long dp[2][(1<<18)+5][22];
void work()
{
	n=read(),m=read();
	ans=0;
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		a[i]=read();
	}
	if(n<=18&&m<=18)
	{
		sort(a,a+n);
		int x=0,y=1;
		dp[0][0][0]=1;
		for(int i=0;i<n;i++)
		{
			x^=1,y^=1;
			for(int j=0;j<(1<<n);j++)
			{
				int s1=0;
				for(int k=0;k<n;k++)
				{
					if(j>>k&1) s1++;
				}
				//cout<<i<<' '<<j<<' '<<s1<<"???\n";
				if(s1!=i) continue;
				for(int k=0;k<=s1;k++)
				{
					if(!dp[y][j][k]) continue;
					//cout<<"!"<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
					for(int p=0;p<n;p++)
					{
						if(j>>p&1) continue;
						dp[x][j|(1<<p)][k+(s[i]=='0'||k>=a[p])]+=dp[y][j][k];
						//cout<<x<<' '<<(j|(1<<p))<<' '<<(k+(s[i]=='0'||k>=a[p]))<<'.'<<p<<'\n';
					}
				}
			}
		}
		long long ans=0;
		for(int i=0;i<=n-m;i++)
		{
			ans+=dp[x][(1<<n)-1][i];
		}
		cout<<ans%mod;	
		return ;
	}
	cout<<0;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int tt=1;
	while(tt--) work();
	return 0;
} 