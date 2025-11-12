#include<bits/stdc++.h>
using namespace std;
int n,a[5005],j,num,ans;
void dfs(int l,int d,int mx)
{
	
	if(d>n)
	{
		if(l>mx*2)
		{
			ans++;
		}
		return;
	}
	dfs(l,d+1,mx);
	dfs(l+a[d],d+1,max(mx,a[d]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
