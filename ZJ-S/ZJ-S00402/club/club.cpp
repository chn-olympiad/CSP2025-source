#include<bits/stdc++.h>
using namespace std;
struct point
{
	int a,b,c;
}p[100005];
int t,n,ans=0;
void dfs(int i,int a,int b,int c,int sum)
{
	if(i==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(a+1<=n/2)dfs(i+1,a+1,b,c,p[i].a+sum);
	if(b+1<=n/2)dfs(i+1,a,b+1,c,p[i].b+sum);
	if(c+1<=n/2)dfs(i+1,a,b,c+1,p[i].c+sum);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i].a>>p[i].b>>p[i].c;
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		
	}
	return 0;
}
