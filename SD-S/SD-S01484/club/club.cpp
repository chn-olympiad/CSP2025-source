#include<bits/stdc++.h>
using namespace std;
int t,n;int dp[300][300][300],ans=0;
struct node{
	int a1,a2,a3;
}a[100010];
void dfs(int q,int q1,int q2,int q3,int s)
{
	if(q1>n/2||q2>n/2||q3>n/2)return;
	ans=max(ans,s);
	if(q>n)return;
	dfs(q+1,q1+1,q2,q3,s+a[q].a1);
	dfs(q+1,q1,q2+1,q3,s+a[q].a2);
	dfs(q+1,q1,q2,q3+1,s+a[q].a3);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a1>>a[i].a2>>a[i].a3;
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
	}
	return 0;
}

