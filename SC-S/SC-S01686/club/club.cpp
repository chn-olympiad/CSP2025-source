#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+10;
int ans;
int n;
int a[N][4];
int vis[N];
int b[N];
int cur;
bool check()
{
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++)
	{
		cnt1+=(vis[i]==1);
		cnt2+=(vis[i]==2);
		cnt3+=(vis[i]==3);
	}
	return (cnt1<=(n/2))&&(cnt2<=(n/2))&&(cnt3<=(n/2));
}
int sum()
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		ret+=a[i][vis[i]];
	}
	return ret;
}
void dfs(int step)
{
	if(step>n)
	{
		if(check()) ans=max(ans,sum());
		return ;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=2;
	dfs(step+1);
	vis[step]=3;
	dfs(step+1);
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cur=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=10)
		{
			dfs(1);
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++) b[++cur]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}