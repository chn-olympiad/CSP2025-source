#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
long long ans;
int a[100005][5],dx[5]={-2,-1,0,1,2},c[3],f[100005][5];
void dfs(int x,int y,long long sum)
{
	if(x==n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<5;i++)
	{
		int tx=x+1;
		int ty=y+dx[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=3&&c[ty]<n/2)
		{
			c[ty]++;
			dfs(tx,ty,sum+a[tx][ty]);
			c[ty]--;
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
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		ans=0;
		memset(c,0,sizeof(c));
		c[1]++;
		dfs(1,1,a[1][1]);
		c[1]--;
		memset(c,0,sizeof(c));
		c[2]++;
		dfs(1,2,a[1][2]);
		c[2]--;
		memset(c,0,sizeof(c));
		c[3]++;
		dfs(1,3,a[1][3]);
		c[3]--;
		cout<<ans<<endl;
	}
    
	return 0;
}
