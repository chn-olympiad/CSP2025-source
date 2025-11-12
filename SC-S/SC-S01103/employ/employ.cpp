#include<bits/stdc++.h>
using namespace std;
const int N=500+5,mod=998244353;
#define int long long
int n,m,c[N],p[N],ans,pre[N],dp[N][N];
char s[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int check()
{
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') 
		{
			num++;
			continue;
		}
		if(num>=c[p[i]]) num++;
	}
	return num<=n-m;
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read(),p[i]=i;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='1');
	if(m==1)
	{
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		sort(c+1,c+n+1,cmp);
		
		int res=1;
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i-1,n-pre[n]);j++) 
			{
				dp[i][j+1]=(dp[i][j+1]+dp[i-1][j]*(n-pre[n]-j))%mod;
				dp[i][j]=(dp[i][j]+dp[i-1][j]*max(0ll,(pre[n]-pre[c[i]]-(i-1-j))))%mod; 
			}
		}
		printf("%lld\n",(ans-dp[n][n-pre[n]]+mod)%mod);
		return 0;
	}
	if(pre[n]==n)
	{
		sort(c+1,c+n+1,cmp);
		int ans=0;
		for(int d=0;d<=n-m;d++)
		{
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<min(i,d+1);j++)
				{
					int k=i-1-j;
					dp[i][j]=(dp[i][j]+dp[i-1][j]*(min(c[i],d+1)+n-d-k-1))%mod;//填入被录取 
					dp[i][j+1]=(dp[i][j+1]+dp[i-1][j]*max(0ll,d-c[i]-j))%mod;
				}
			}
			ans=(ans+dp[n][d])%mod;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=10)
	{
		ans=0;
		ans+=check();
		while(next_permutation(p+1,p+n+1)) ans+=check();
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
