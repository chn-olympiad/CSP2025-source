#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
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
void dfs(int x,int cnt,int fail)
{
	if(x>n)
	{
		if(cnt>=m)
			ans=(ans+1)%mod;
		return;
	}
	if(cnt+(n-x+1)<m)	return;
	if(cnt>=m)//录用够了 
	{
		int sh=n-x+1;
		ans=(ans+f(sh))%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			used[i]=1;
			if(fail<c[i]&&s[x]=='1')
				dfs(x+1,cnt+1,fail);//录用 
			else	dfs(x+1,cnt,fail+1);//被拒绝或走人 
			used[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	int len=strlen(s+1),mi=1e9;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mi=min(c[i],mi);
	}
	int flag=0;
	for(int i=1;i<=len;i++)
		if(s[i]=='0') flag++;
	if(flag==0&&mi>0)
		printf("%lld",f(n));
	else
	{
		dfs(1,0,0);
		printf("%lld",ans);
	}
	return 0;
}
