#include<bits/stdc++.h>
using namespace std;
long long n,mod=998244353,a[5005];
long long ans,maxx;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int k,long long sum,int stat)
{
	if(k==0)
	{
//		cout<<sum<<'*'<<maxx<<endl;
		if(sum>maxx*2)
		{
			ans=(ans+1)%mod;
		}
	}
	else
	{
		for(int i=stat+1;i<=n;i++)
		{
			int tmp=maxx;
			maxx=max(maxx,a[i]);
			if(maxx*2>=sum+k*a[i]) continue;
			else dfs(k-1,sum+a[i],i);
			maxx=tmp;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++) dfs(i,0,0);//cout<<maxx<<endl;
	cout<<ans;
	return 0;
}
