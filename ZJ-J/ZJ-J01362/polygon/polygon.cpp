#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long b[6010],MAX,n,a[5010],ans;
void add(long long x)
{
	int pd;
	for(int i=MAX+1;i>=0;i--)
	{
		pd=min(i+x,MAX+1);
		b[pd]=(b[i]+b[pd])%mod;
	}
}
long long query(long long x)
{
	long long sum=0;
	for(int i=x+1;i<=MAX+1;i++)
	{
		sum=(sum+b[i])%mod;
	}
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		MAX=max(MAX,a[i]);
	}
	sort(a+1,a+n+1);
	b[0]=1;
	add(a[1]);add(a[2]);
	for(int i=3;i<=n;i++)
	{
		ans=(ans+query(a[i]))%mod;
		add(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
//80min AK!!!
