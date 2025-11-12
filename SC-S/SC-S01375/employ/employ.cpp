#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL MOD=998244353;
LL n;
LL jc(LL x)
{
	LL ans=1;
	for(LL i=1;i<=x;i++)
	{
		ans=ans*i%MOD;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cout<<(n%2?jc(n):0);
	return 0;
}