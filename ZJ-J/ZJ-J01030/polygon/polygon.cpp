#include<bits/stdc++.h>
using namespace std;
int a[5050];
int n;
int cnt=0;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[1])return 0;
	}
	return 1;
}
void dfs(int ma,int sum,int pre)
{
	if(sum>ma*2)cnt++;
	for(int i=pre+1;i<=n;i++)
	{
		dfs(a[i],sum+a[i],i);
	}
	return;
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
	if(n==3)
	{
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	else if(check())
	{
		cout<<n-2;
		return 0;
	}
	else 
	{
		dfs(0,0,0);
		cout<<cnt;
	}
	return 0;
}
