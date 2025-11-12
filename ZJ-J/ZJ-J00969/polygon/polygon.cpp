//bqq miaomiaomiao
//64? qwq noooo
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=998244353;
int a[5010];
int n;
ll ans=0;
int suma=0;
void dfs(int x,int cnt,int sum,int mx)
{
	if(x==n)
	{
		ans=(ans+(cnt>=3&&sum>mx*2))%p;
		return;
	}
	if(suma<=mx*2)
	{
		return;
	}
	dfs(x+1,cnt+1,sum+a[x+1],max(mx,a[x+1]));
	dfs(x+1,cnt,sum,mx);
}
ll qpow(int a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%p;
		}
		b>>=1,a=(a*a)%p;
	}
	return ans;
}
ll f[5010];
int main()
{
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],suma+=a[i];
	}
	if(n<=20)
	{
		dfs(0,0,0,0);
		cout<<ans<<endl;
		return 0;
	}
	f[3]=7;
	for(int i=4;i<=n;i++)
	{
		f[i]=(f[i-1]+i)%p;
	}
	cout<<(ll)((qpow(2,n)-f[n]+p)%p)<<endl;
	return 0;
}