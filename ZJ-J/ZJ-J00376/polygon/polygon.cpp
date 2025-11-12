#include<bits/stdc++.h>
#define ll long long
#define db double
const ll N=1e6+10,mod=998244353;
ll t[N],n,a[N],vis[N];
int C(int n,int m)
{
	return t[n]/t[m]/t[n-m];
}
using namespace std;
void f()
{
	ll ans=0;
	for(int i=3;i<=n;i++)
	{
		ans=(ans+C(n,i))%mod;
		cout<<ans<<"\n";
	}
	cout<<ans;
	return ;
}
void init()
{
	t[0]=1;
	for(int i=1;i<=5000;i++)
		t[i]=(t[i-1]*i)%mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[a[i]]++;
	}
	if(vis[1]==n)
	{
		f();
		return 0;
	}
	sort(a+1,a+n+1);
	return 0;
}
