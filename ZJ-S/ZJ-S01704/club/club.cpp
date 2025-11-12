#include<iostream>
using namespace std;
int t,n,a[100001][4],c[4],ans;
void dfs(int id,int s)
{
	if(c[1]>n/2||c[2]>n/2||c[3]>n/2)return;
	if(id==n)ans=max(ans,s);
	for(int i=1;i<=3;i++)
	{
		c[i]++;
		dfs(id+1,s+a[id+1][i]);
		c[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		a[100001][4]={},c[4]={},ans=0;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=3;i++)
		{
			c[i]++;
			dfs(1,a[1][i]);
			c[i]--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
