#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10000];
long long int cnt=1;
void dfs(int m,int ans,int s)
{
	if(m>n)	return ;
	ans+=a[m];	
	if(ans>=a[m]*2&&s>=3)	
	{
		cnt++;
		return;
	}
	for(int i=1;i<=n-m;i++)
	{
		dfs(m+i,ans,s+1);
	}
	if(s==1)	dfs(m+1,0,1);
	return ;
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
	sort(a+1,a+n+1);
	dfs(1,0,1);
	cout<<cnt%998224353;
	return 0;
}
