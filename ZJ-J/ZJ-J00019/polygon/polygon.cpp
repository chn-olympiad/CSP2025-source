#include<bits/stdc++.h>
using namespace std;
int n,a[5005],num;
void dfs(int he,int maxn,int cen,int now)
{
	if(cen>=3&&he>maxn*2) num=(num+1)%998244353;
	if(now==n) return;
	for(int i=now+1;i<=n;i++)
	{
		dfs(he+a[i],max(maxn,a[i]),cen+1,i);
	}
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
	for(int i=1;i<=n;i++)
	{
		dfs(a[i],a[i],1,i);
	}
	cout<<num;
	return 0;
}
