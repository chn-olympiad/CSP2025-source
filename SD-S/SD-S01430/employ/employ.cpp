//longlong? MLE? clear?
#include<bits/stdc++.h>
#define LOCAL
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,ans;
int vis[N],c[N],p[N];
char s[N];
void dfs(int stp)
{
	if(stp==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[p[i]])
			{
				cnt++;
				continue;
			}
			if(s[i]=='0')
			{
				cnt++;
			}
		}
		if(n-cnt>=m)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		p[stp]=i;
		vis[i]=1;
		dfs(stp+1);
		p[stp]=0;
		vis[i]=0;
	}
}
int main()
{
	#ifdef LOCAL
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d\n",ans);
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
}
