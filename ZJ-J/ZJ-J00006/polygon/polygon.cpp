#include<bits/stdc++.h>
using namespace std;
const int k=998244353;
int n,a[5010],Max;
int dfs(int x,int y,int len,int S)
{
	int u=0;
	for(int i=y+1;i<=n;i++)
	{
		if(len>=2&&S>a[i]) u=(u+1)%k;
		u=(u+dfs(y,i,len+1,S+a[i]))%k;
	}
	return u;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		cout<<(n-2)*(n-1)/2<<endl;
		return 0;
	}
	if(n<=3)
	{
		if(a[3]<a[1]+a[2]) cout<<1<<endl;
		  else cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) Max=(Max+dfs(0,i,1,a[i]))%k;
	cout<<Max<<endl;
	return 0;
}