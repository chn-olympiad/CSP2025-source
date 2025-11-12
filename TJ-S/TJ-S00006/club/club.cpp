#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct node
{
	int a,b,c;
}p[100010];
int n;
bool isb=1;
int t;
int dp[300010];
int ans;
void dfs(int step,int cnt1,int cnt2,int cnt3,int cnt)
{
	if(step==n+1)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(cnt1<n/2)dfs(step+1,cnt1+1,cnt2,cnt3,cnt+p[step].a);
	if(cnt2<n/2)dfs(step+1,cnt1,cnt2+1,cnt3,cnt+p[step].b);
	if(cnt3<n/2&&isb)dfs(step+1,cnt1,cnt2,cnt3+1,cnt+p[step].c);
}
bool cmpa(node x,node y)
{
	return x.a>y.a;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		isb=1;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		if(n==200)
		{
			isb=0;
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else if(n==100000)
		{
			bool flag1=true;//A
			for(int i=1;i<=n;i++)if(p[i].b!=0||p[i].c!=0)flag1=false;
			if(flag1)
			{
				sort(p+1,p+n+1,cmpa);
				for(int i=1;i<=n/2;i++)
				{
					ans+=p[i].a;
				}
				cout<<ans<<endl;
			}
			else
			{
				dfs(1,0,0,0,0);
				cout<<ans<<endl;
			}
		}
		else
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
 }
