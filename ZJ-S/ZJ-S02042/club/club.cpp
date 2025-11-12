#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct sd
{
	int aa;
	int bb;
	int cc;
}st[100005];
int ans;
int a,b,c;
void dfs(int now,int a,int b,int c,int anss)
{
	if(now==n+1)
	{
		ans=max(ans,anss);
		return;
	}
	if(a>=1)	dfs(now+1,a-1,b,c,anss+st[now].aa);
	if(b>=1)	dfs(now+1,a,b-1,c,anss+st[now].bb);
	if(c>=1)	dfs(now+1,a,b,c-1,anss+st[now].cc);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>st[i].aa>>st[i].bb>>st[i].cc;
		}
		dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<endl;
	}
	return 0;
}
