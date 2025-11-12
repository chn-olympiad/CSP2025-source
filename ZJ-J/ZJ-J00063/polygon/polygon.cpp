#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005],ans;
void dfs(int l,int sum,int maxx,int t)
{
	if(t>n)return ;
	if(t>=3)
	{
		if(sum>maxx*2)
		ans++,ans%=mod;
	}
	for(int i=l+1;i<=n;i++)
	dfs(i,sum+a[i],a[i],t+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	cout<<ans%mod;
	return 0;
}
/*
1 2 3
1 2 3 4
1 2 3 5
1 2 4 
1 2 4 5
1 2 5
*/
