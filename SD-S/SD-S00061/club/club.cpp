#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000],c[100000],ans;
void dfs(int step,int x,int y,int z,int sum)
{
	if(step==n+1)
	{
		ans=max(ans,sum);
	}
	if(x<n/2) dfs(step+1,x+1,y,z,sum+a[step]);
	if(y<n/2) dfs(step+1,x,y+1,z,sum+b[step]);
	if(z<n/2) dfs(step+1,x,y,z+1,sum+c[step]);
	
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
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=15)
		{
			ans=0; 
			dfs(1,0,0,0,0);
			cout<<ans;
		}

	}
	return 0;
}

