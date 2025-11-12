#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5001],p[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,t,ans,sum;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	t=1;
	p[0]=1;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=0;j<=a[i];j++)
			sum=(sum+p[j])%mod;
		ans=(ans+(t+mod-sum)%mod)%mod;
		for(int j=5000;j>=a[i];j--)
			p[j]=(p[j]+p[j-a[i]])%mod;
		t=t*2%mod;
	}
	cout<<ans;
	return 0;
}
