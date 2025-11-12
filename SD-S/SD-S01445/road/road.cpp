#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,costm[200000]={0},ans=0,a,b;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>costm[i];
	}
	if(k==0)
	{
		sort(costm,costm+1);
		for(int i=1;i<=m;i++)
		{
			ans+=costm[i];
		}
		cout<<ans<<endl;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
