#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5100];
long long n,cnt,s;
void dfs(int step,int maxn,long long ans)
{
	if(ans>2*maxn&&step==n) 
		cnt=(cnt+1)%mod;
	if(step==n) return ;
	if(a[step+1]>maxn) 
		dfs(step+1,a[step+1],ans+a[step+1]);
	else dfs(step+1,maxn,ans+a[step+1]);
	dfs(step+1,maxn,ans);
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
		if(a[i]==1) s++;
	}
	if(s==n)
	{
		long long cnt1=1;
		for(int i=3;i<=n;i++)
		{
			if(i==3)
			{
				for(int j=max(i,n-i)+1;j<=n;j++)
					cnt1=cnt1*j;
				for(int j=2;j<=min(i,n-i);j++)
					cnt1=cnt1/j;
			}
			else 
				cnt1=cnt1*min(i-1,n-i+1)/max(i,n-i);
			cnt=(cnt+cnt1)%mod;
		}
		cout<<cnt;
		return 0;
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}
