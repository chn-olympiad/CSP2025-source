#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m;
string s;
ll c[505];
ll res=1;
void quan(ll x)
{
	for(int i=1;i<=x;i++)
		res=(res*i)%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	quan(m);
	cout<<res;
	return 0;
}

