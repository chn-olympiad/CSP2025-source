#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i_[501],a;string s;
const ll q=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld",&n);
	i_[1]=1;
	for(int i=2;i<=n+2;i++)
	{
		i_[i]=i_[i-1]*i%q;
		cin>>a;
	}
	printf("%lld",i_[n]);
	return 0;
}
