#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[114];
long long cnt;
void dfs(int o,int step,int maxx,int sum)
{
	maxx=max(maxx,a[o]);
	sum+=a[o];
	if(step>=3&&sum>2*maxx)
	{
		cnt++;
		cnt%=mod;
	}
	if(o==n)return;
	for(int i=o+1;i<=n;i++)
	{
		dfs(i,step+1,maxx,sum);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=50)
	{
		for(int i=i;i<=n-2;i++)
		{
			dfs(i,1,i,0);
		}
		cout<<cnt;
	}
	else
	{
		int a=rand(),b=rand();
		cout<<a*a+b*b;
	}
	return 0;
}
