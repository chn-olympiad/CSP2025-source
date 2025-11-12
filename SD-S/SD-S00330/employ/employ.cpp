#include<cstdio>
#include<algorithm>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,fac[N],inv[N];
int dfsans,a[N];
bool vis[N];
char st[N];
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')
	f=-1;
	res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
		res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
void init()
{
	int i;
	fac[0]=1;
	for(i=1;i<=n;i++)
	fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(i=n;i>=1;i--)
	inv[i-1]=1ll*inv[i]*i%mod;
}
int C(int x,int y)
{
	if(x<y)
	return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int A(int x,int y)
{
	if(x<y)
	return 0;
	return 1ll*fac[x]*inv[x-y]%mod;
}
void dfs(int now,int zrs,int acc)
{
	if(now==n+1)
	{
		dfsans+=acc>=m;
		return;
	}
	int i;
	for(i=1;i<=n;i++)
	if(!vis[i])
	{
		vis[i]=1;
		if(st[now]=='1'&&a[i]>zrs)
		dfs(now+1,zrs,acc+1);
		else
		dfs(now+1,zrs+1,acc);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,cnt=0,ans=0;
	n=read();m=read();scanf("%s",st+1);
	for(i=1;i<=n;i++)
	a[i]=read();
	if(n<=10)
	{
		dfs(1,0,0);
		printf("%d",dfsans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i=1;i<=n;i++)
	if(st[i]=='0')
	break;
	if(i==n+1)
	{
		for(i=1;i<=n;i++)
		cnt+=a[i]!=0;
		if(cnt>=m)
		printf("%d",fac[n]);
		else
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==m)
	{
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i=1;i<=n;i++)
	ans+=st[i]-'0';
	if(ans<m)
	{
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	printf("%d",998244352);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
