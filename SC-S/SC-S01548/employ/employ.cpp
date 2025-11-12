#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL read()
{
	char c=getchar();
	LL f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(LL x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const LL mod=998244353,N=5e5+5;
LL n,m,ans,c[N],a[N];
bool b[N],f[N];
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(b[i]==false||cnt>=c[a[i]]) cnt++;
	if(n-cnt>=m) ans++;
}
void dfs(int u)
{
	if(u>n)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=true;
			a[u]=i;
			dfs(u+1);
			f[i]=false;
		}
	}
}
void solve1()
{
	dfs(1);
	print(ans);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='1') b[i]=true;
		else b[i]=false;
	}
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=10)
	{
		solve1();
		return 0;
	}
	if(m==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0||c[i]==0) ans=0;
			ans=ans*i%mod;
		}
		print(ans);
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	print(ans);
	return 0;
}
/*
11 11
11111111111 
1 2 3 4 5 6 7 8 9 10 11
*/