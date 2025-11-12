#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],ans,m=-1,p1=0,p2=0,p3=0;
void dfs(int d)
{
	if(d==n+1)
	{
		if(ans>m)
		{
			m=ans;
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		ans+=a[d][i];
		dfs(d+1);
		ans-=a[d][i];
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		m=-1;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1];
			cin>>a[j][2];
			cin>>a[j][3];
		}
		dfs(1);
		cout<<m<<endl;
	}
	return 0;
}

