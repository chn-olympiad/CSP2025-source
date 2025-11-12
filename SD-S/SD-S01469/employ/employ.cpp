#include<iostream>
#include<utility>
#include<algorithm>
#include<deque>
using namespace std;
const int N=514,mod=998244353;
bool a[N];
int c[N];
int n,m;
int ans=0;
bool vis[N];
void dfs(int x,int cnt)
{
	if(n-cnt<m)
		return ;
	if(x==n)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		vis[i]=1;
		if(a[x+1]&&cnt<c[i])
			dfs(x+1,cnt);
		else
			dfs(x+1,cnt+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		a[i]=s[i-1]=='1';
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	dfs(0,0);
	cout<<ans;
	printf("%d",ans);
	return 0;
}
/*
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
freopen(".in","w",stdin);
freopen(".out","r",stdout);
feropen(".in","r",stdin);
feropen(".out","w",stdout);
I'm luogu uid748678.
Maybe it's my last year in CSP/NOIP.
Hope everything goes best.
*/
