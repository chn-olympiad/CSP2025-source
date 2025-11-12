#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long ans = 0;
void dfs(long long bian,long long maxn,long long num,int b2,long long last)
{
	if(b2 == bian)
	{
		if(num>maxn*2)
		{
			ans = (ans+1)%998244353;
			return ;
		}
	}
	else
	{
		for(int i = last;i<n;i++)
		{
			dfs(bian,max(maxn,a[i]),num+a[i],b2+1,i+1);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(long long i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i = 3;i<n;i++)
	{
		dfs(i,0,0,0,0);
	}
	cout<<ans<<endl;
	return 0;
}
