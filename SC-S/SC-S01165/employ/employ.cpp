#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a1,a2,a[512],b[512],ans,vis[512];
void dfs(int dep,int sx)
{
	if(n-sx<m)
	{
		return;
	}
	if(dep>n)
	{
		if(n-sx>=m)
		{
			++ans;
			ans%=mod;
			return;
		}
	}
	for(int i=1;i<=n;++i)
	{		
		if(!vis[i])
		{
			vis[i]=1;
			if(a[dep])
			{
				if(sx<b[i])
				{
					dfs(dep+1,sx);
				}
				else
				{
					dfs(dep+1,sx+1);
				}
			}
			else
			{
				dfs(dep+1,sx+1);
			}
			vis[i]=0;
		}
	}
	return;
}
long long read()
{
	char ch=getchar();
	long long x=0;
	while(ch<'0'||'9'<ch)
	{
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x;
}
int read2()
{
	char ch=getchar();
	while(ch!='0'&&ch!='1')
	{
		ch=getchar();
	}
	if(ch=='0')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read2();
		if(a[i])
		{
			++a1;
		}
		else
		{
			++a2;
		}
	}
	for(int i=1;i<=n;++i)
	{
		b[i]=read();
	}
	sort(b+1,b+n+1);
	if(a1<m)
	{
		printf("0");
		return 0;
	}
	if(b[n-m+1]==0)
	{
		printf("0");
		return 0;
	}
	if(m==n)
	{
		if(b[1]==0||a2)
		{
			printf("0");
			return 0;
		}
		ans=1;
		for(long long i=2;i<=n;++i)
		{
			ans=ans*i%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}