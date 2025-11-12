#include <bits/stdc++.h>
using namespace std;
int vis[1005],int ans,a[1005],n;
void dfs(int k,int d)
{
	if(k>n)
	{
		return ;
	}
	cout<<k<<" "<<d<<" "<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			continue;
		}
		vis[i]==1;
		ans=d;
		dfs(k+1,d+i);
		dfs(k+1;d*2+i)
	}
}
int main()
{
	
	return 0;
}
