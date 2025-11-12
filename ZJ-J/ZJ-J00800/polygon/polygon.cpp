#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010][3];
long long cnt;
void dfs(int ans,int nmax,int i)
{
	if(ans>nmax*2)
	{
		cnt++;
		cnt%=998244353;
		return ;
	}
	for(;i<=n;i++)
	{
		dfs(ans,a[i-1],i);
		dfs(ans+a[i],a[i],i);
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
	dfs(0,a[1],1);
	cout<<cnt;
	return 0;
 }
