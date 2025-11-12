#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int t,n,a[100010],b[100010],c[100010];
int ans=-1,sum;
bool vis[100010],flag3,flag2,flag1;
void dfs(int x,int y,int z)
{
	for(int i=1;i<=n;i++)
	{
		if(x+1<=n/2&&!vis[i]&&!flag1) 
		{
			sum+=a[i]; vis[i]=true;
			if(sum>ans) ans=sum;
			dfs(x+1,y,z);
			sum-=a[i]; vis[i]=false;
		}
		if(y+1<=n/2&&!vis[i]&&!flag2)
		{
			sum+=b[i]; vis[i]=true;
			if(sum>ans) ans=sum;
			dfs(x,y+1,z);
			sum-=b[i]; vis[i]=false;
		}
		if(z+1<=n/2&&!vis[i]&&!flag3)
		{
			sum+=c[i]; vis[i]=true;
			if(ans<sum) ans=sum;
			dfs(x,y,z+1);
			sum-=c[i]; vis[i]=false;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	I AK CSP
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=-1;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0) flag1=true;
			if(b[i]!=0) flag2=true;
			if(c[i]!=0) flag3=true;
		}
		dfs(0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}