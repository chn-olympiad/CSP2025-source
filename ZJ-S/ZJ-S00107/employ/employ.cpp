#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int Mod=998244353;
int n,m,a[N],t[N],answ;
char s[N];
bool vis[N];
int l[N];
void dfs(int rt)
{
	if(rt==n)
	{
		int res=0;
		for(int i=1,cnt=0;i<=n;++i)
		{
			if(cnt>=l[i]||s[i-1]=='0') cnt++;
			else res++;
		}
		if(res>=m) answ++;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			vis[i]=1;
			l[rt+1]=a[i];
			dfs(rt+1);
			vis[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	bool fg=1;
	for(int i=0;i<n;++i) fg=fg&&(s[i]=='1');
	for(int i=1;i<=n;t[a[i]]++,++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n<=10)
	{
		dfs(0);
		printf("%lld\n",answ%Mod);
		return 0;
	}
	if(m==n) 
	{
		if(!fg||t[0])
		{
			puts("0");
			return 0;
		}
		int ans=1;
		for(int i=2;i<=n;++i) ans=ans*i%Mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(fg)
	{
		int ans=1;
		if(n-t[0]<m)
		{
			puts("0");
			return 0;
		}
	}
	return 0;
}
