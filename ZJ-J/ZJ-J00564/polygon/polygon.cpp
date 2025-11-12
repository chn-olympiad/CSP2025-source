#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,mod=998244353;
vector<long long> a(5010,0);
void dfs(long long step,long long maxx,long long num)//where max sum
{
	if(step>n)
	{
		if(num>2*maxx)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(step+1,max(maxx,a[step]),num+a[step]);
	dfs(step+1,maxx,num);
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
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
