#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int p,int sum,int maxx,bool flag)
{
	if(p>n)return;
	if(sum>2*maxx&&flag)ans++;
	dfs(p+1,sum+a[p+1],a[p+1],1);
	dfs(p+1,sum,maxx,0);
}
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}

