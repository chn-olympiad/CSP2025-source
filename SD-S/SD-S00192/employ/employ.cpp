#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,m,c[N],vis[N],ans,p[N];
char s[N];
inline bool check()
{
	int num=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt<c[p[i]]&&s[i]=='1') num++;
		else cnt++;
	}
	if(num>=m) return 1;
	return 0;
}
inline void dfs(int step)
{
	if(step==n+1)
	{
		if(check()) ans++,ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
	return ;
}
signed main() 
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m)
	{
		bool flag=1;
		for(int i=1;i<=n;i++) if(s[i]!='1'||!c[i]) flag=0;
		if(!flag) cout<<0<<endl;
		else
		{
			int ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
