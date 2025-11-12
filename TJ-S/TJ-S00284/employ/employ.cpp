#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

const int N=555;
const db eps=1e-8;
const ll MOD=998244353;
string s;
int a[N];
int b[N];
int n,m;
ll ans;
int vis[N];
bool check()
{
	int tot=0,k=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(k>=b[i])continue;
		if(s[tot]=='1')cnt++;
		if(cnt>=m)return 1;
		tot++;
	}
	return 0;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		if(check())ans++;
		return ;
	}
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		b[dep]=a[i];
		vis[i]=1;
		dfs(dep+1);
		vis[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[i]);
		if(s[i-1]=='1')k++;
	}
	if(k==0)return puts("0"),0;
	if(m<=k)
	{
		ll ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=(ans*i)%MOD;
		}
		printf("%lld",ans);
	}
	if(m<=10)
	{
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
