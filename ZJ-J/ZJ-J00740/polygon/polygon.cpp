#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],ans=0,i,n,ansans=0;
map<long long,map<long long,long long> >c;
void dfs(long long x,long long k)
{
	long long i;
	if(x==n+1)
	{
		long long sum=0;
		sort(b+1,b+k+1);
		for(i=1;i<=k-1;i++)sum+=b[i];
		if(sum>b[k])ans++;
		ans%=998244353;
		return;
	}
	b[k+1]=a[x];
	dfs(x+1,k+1);
	b[k+1]=0;
	dfs(x+1,k);
}
void pre()
{
	long long i,j;
	for(i=1;i<=5000;i++)
	{
		c[i][0]=c[i][i]=2;
		for(j=1;j<i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%998244353;
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
	for(i=1;i<=n;i++)cin>>a[i];
	if(n<=20)
	{
	dfs(1,0);
	cout<<ans;
}
    else
    {
    	for(i=3;i<=n;i++)
    	{
    		ansans+=c[n][i];
		}
		cout<<ansans;
	}
	return 0;
}
