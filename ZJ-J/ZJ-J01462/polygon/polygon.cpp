#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N=5e3+5;
ll n,a[N],sum,f=1,ans,zb[N],sl[N];
ll C(int n,int m)
{
	int x=1,c=2;
	for(int i=n;i<=m;i++)
	{
		x*=i;
		if(x%c==0&&c<m-n)
		{
			x/=c;
			c++;
		}
		x%=998244353;
	}
	return x;
}
void dfs(int now,int lst,int n,int s)
{
	if(now>sum&&s>=3)
	{
		ans+=1;
		ans%=998244353;
	}
	for(int i=lst+1;i<n;i++)
	{
		dfs(now+a[i],i,n,s+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f)
	{
		for(int i=3;i<=n;i++)
		{
			
			for(int j=2;j<i/2;j++)
			{
				ans+=C(j,i);
				ans%=998244353;
			}
			ans+=n+1;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		sum=a[i]*2;
		dfs(a[i],0,i,1);
	}
	cout<<ans<<endl;
	return 0;
}
