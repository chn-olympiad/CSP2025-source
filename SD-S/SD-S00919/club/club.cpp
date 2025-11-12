#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,ans,lim,a[100005][4],b[100005];
int t;
void dfs(int step,long long tot,int an,int bn,int cn)
{
	if(step==n+1)
	{
		if(an>lim||bn>lim||cn>lim)
		{
			return;
		}
		ans=max(tot,ans);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			dfs(step+1,tot+a[step][i],an+1,bn,cn);
		}
		if(i==2)
		{
			dfs(step+1,tot+a[step][i],an,bn+1,cn);
		}
		else
		{
			dfs(step+1,tot+a[step][i],an,bn,cn+1);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		lim=n/2;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2)
		{
			cout<<max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))));
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;	
	}
	return 0;
}
//I love CCF 
