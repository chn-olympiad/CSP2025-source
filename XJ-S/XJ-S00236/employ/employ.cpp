#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,m;
ll work(ll n,ll a)
{
	ll i,j;
	ll x=1,y=1;
	for(i=a+1;i<=n;i++)
	{
		x=x*i%mod;
	}
	for(i=1;i<=n-a;i++)
	{
		y=y*i%mod; 
	}
	ll z=x/y%mod;
	return z;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int i,j,k=0;
	cin>>j;
	for(i=1;i<=n;i++)
	{
		cin>>j;
		if(j==0) k++;
	}
	n=n-k;
	ll ans=work(n,m);
	cout<<ans;
	return 0;
}
