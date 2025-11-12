#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N];
unsigned long long res;
unsigned long long C(int a,int b)
{
	unsigned long long ans=1;
	b=min(b,a-b);
	for(int i=1;i<=b;i++)
	{
		ans*=a-i+1;
	}
	for(int i=1;i<=b;i++)
	{
		ans/=i;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		res=(res+C(n,i))%MOD;
	}
	cout<<res;
	return 0;
}