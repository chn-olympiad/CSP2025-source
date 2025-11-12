#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],a[510];
long long ans=0;
char s[510];
const int mod=998244353;
bool used[510];
long long f(long long x)
{
	long long a=1;
	while(x--)
		a=(a*(x+1))%mod;
	return a;
}
void dfs(int x,int cnt)
{
	if(x>n)
	{
		if(cnt>=m)
			ans=(ans+1)%mod;
		return;
	}
	if(cnt+(n-x+1)<m)	return;
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			used[i]=1;
			if(a[x]<c[i]&&s[x]=='1')
				dfs(x+1,cnt+1);
			else	dfs(x+1,cnt);
			used[i]=0;
		}
	}
}
int main()
{
	cin>>n>>m>>s+1;
	int len=strlen(s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int flag=0;
	for(int i=1;i<=len;i++)
	{
		a[i]+=a[i-1];
		if(s[i]=='0')
			a[i+1]++,flag++;
	}
	if(flag==0)
		printf("%lld",f(n));
	else
	{
		dfs(1,0);
		printf("%lld",ans);
	}
	return 0;
}

