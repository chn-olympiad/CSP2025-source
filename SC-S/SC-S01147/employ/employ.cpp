#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long

using namespace std;

const int N = 510 , MOD = 998244353;

int n,m,c[N],ans = 1;
string s;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&c[i]);
		ans = (1ll* ans * i) % MOD;
	}
	cout<<ans<<"\n";
	return 0;
}