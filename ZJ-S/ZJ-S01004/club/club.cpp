#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	long long a,b,c;
}x[N];
long long maxn,n,cnt1,cnt2,cnt3;
int vis[N];
void dfs(int step,long long ans)
{
	maxn=max(maxn,ans);
	if(step==n) return ;
	if(vis[step+1]==0&&cnt1+1<=n/2)
	{
		cnt1++;
		vis[step+1]=1;
		dfs(step+1,ans+x[step+1].a);
		cnt1--;
		vis[step+1]=0;
	}
	if(vis[step+1]==0&&cnt2+1<=n/2)
	{
		cnt2++;
		vis[step+1]=1;
		dfs(step+1,ans+x[step+1].b);
		cnt2--;
		vis[step+1]=0;
	}
	if(vis[step+1]==0&&cnt3+1<=n/2)
	{
		cnt3++;
		vis[step+1]=1;
		dfs(step+1,ans+x[step+1].c);
		cnt3--;
		vis[step+1]=0;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>x[i].a>>x[i].b>>x[i].c;
		cnt1=0,cnt2=0,cnt3=0;
		dfs(0,0);
		printf("%lld\n",maxn);
	}
	return 0;
}
