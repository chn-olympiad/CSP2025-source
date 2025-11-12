#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],m;
void dfs(long long sum,int ans,int x,long long MAX)
{
	if(ans>=3&&sum>MAX*2)
	{
		m++;
		m%=998244353;
	}
	for(int j=x+1;j<=n;j++) dfs(sum+a[j],ans+1,j,max(MAX,a[j]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dfs(a[i],1,i,a[i]);
	cout<<m<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}