#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int ls,int sum,int maxx)
{
	if(ls==n+1)
	{
//		cout<<sum<<' '<<maxx<<endl;
		if(sum>2*maxx)
		{
			ans=(ans+1)%998244353;
		}
		return;
	}
//	cout<<ls<<endl;
	dfs(ls+1,sum+a[ls],max(maxx,a[ls]));
	dfs(ls+1,sum,maxx);
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
	dfs(1,0,0);
	cout<<ans;
	return 0;
}