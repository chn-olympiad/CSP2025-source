#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n=0,a[5005],sum,t,maxxx;
void dfs(int b,int x,int t,int w)
{
	if(b>=3){
		if(t>x*2){
			sum=(sum+1)%998244353;
		}
	}
	for(int i=w+1;i<=n;i++)
	{
		dfs(b+1,max(x,a[i]),t+a[i],i);
	}
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
	for(int i=1;i<=n;i++){
		dfs(1,a[i],a[i],i);
	}
	cout<<sum%998244353;
	return 0;
}
