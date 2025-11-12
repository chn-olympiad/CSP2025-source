#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int club1,club2,club3;
int vis1[N],vis2[N],vis3[N],a1[N],a2[N],a3[N];
struct P
{
	int a1,a2,a3,id;
}a[N];
bool cmp1(P a,P b)
{
	return a.a1>b.a1;
}
bool cmp2(P a,P b)
{
	return a.a2>b.a2;
}
bool cmp3(P a,P b)
{
	return a.a3>b.a3;
}
int dp[N][2];
int n,ans;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int now,int cnt)
{
	if(now==n+1)
	{
		ans=max(ans,cnt);
		//cout<<cnt<<'\n';
		return ;
	}
	if(club1+1<=n/2&&!vis1[now])
	{
		vis1[now]=1;
		club1++;
		dfs(now+1,cnt+a1[now]);
		vis1[now]=0;
		club1--;
	}
	if(club2+1<=n/2&&!vis2[now])
	{
		vis2[now]=1;
		club2++;
		dfs(now+1,cnt+a2[now]);
		vis2[now]=0;
		club2--;
	}
	if(club3+1<=n/2&&!vis3[now])
	{
		vis3[now]=1;
		club3++;
		dfs(now+1,cnt+a3[now]);
		vis3[now]=0;
		club3--;
	}
}
void clear()
{
	memset(vis1,0,sizeof vis1);
	memset(vis2,0,sizeof vis2);
	memset(vis3,0,sizeof vis3);
	memset(a1,0,sizeof a1);
	memset(a2,0,sizeof a2);
	memset(a3,0,sizeof a3);
	memset(dp,0,sizeof dp);
	club1=0,club2=0,club3=0,ans=0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		clear();
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a3[i])flag1=1;
			if(a2[i])flag2=1;
		}
		if(!flag1&&!flag2)
		{
			sort(a1+1,a1+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2)
				ans+=a1[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		
		
		dfs(1,0);
	//cout<<"\n-------\n";
		cout<<ans<<'\n';
	//	cout<<"\n-------\n";
	}
    return 0;
}
/*
1
4
1 1 0
4 5 0
1 4 0
1 9 0
*/


