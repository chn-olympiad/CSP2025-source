#include<bits/stdc++.h>
using namespace std;
int a[5005],w;
long long ans;
void dfs(long long num,int maxx,int s,int q)
{
	if(maxx*2<num&&q>2){
	ans++;
	ans%=998244353;}
	if(s==w)return;
	for(int i=s+1;i<=w;i++)
	{
		dfs(num+a[i],max(maxx,a[i]),i,q+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>w;
	for(int i=1;i<=w;i++)cin>>a[i];
	dfs(0,-1,0,0);
	cout<<ans;
	return 0;
}
