#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],da,mx,h,jss,z,zz;
const ll mod=998244353;
bool tsxz=1,x[5005];
ll ksm(ll n,ll a){ll daa=1;while(a){daa=(daa*daa)%mod;if(a&1) daa=(daa*n)%mod;a/=2;}return daa%mod;}
void dfs(int js,bool xu)
{
	if(js==n+1)
	{
		mx=-1999999999,h=0,jss=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]==1)
			{
				h+=a[i];mx=max(mx,a[i]);jss++;
			}
		}
		if(h>(mx*2)&&jss>=3)
		{
			da=(da+1)%mod;
			//for(int i=1;i<=n;i++) cout<<x[i]<<" ";
			//cout<<endl;
		}
		return;
	}
	x[js]=xu;
	dfs(js+1,1);
	if(js!=n) dfs(js+1,0);
}
void sol_20()
{
	dfs(1,0);
	dfs(1,1);
	cout<<da;
}
void sol_ts()
{
	for(int i=3;i<=n;i++)
	{
		z=zz=1;
		for(int j=n;j>=n-i+1;j--) z=(z*j)%mod;
		for(int j=2;j<=i;j++) zz=(zz*j)%mod;
		//da+=(ksm(zz,mod-2)/z)%mod;
		da+=(z/zz)%mod;
	}
	cout<<da;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) tsxz=0;
	}
	if(n<=20) sol_20();
	else if(tsxz) sol_ts();
	else sol_20();
	return 0;
}

