#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m;
ll jc[507];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		jc[i]=(jc[i-1]%mod*i%mod)%mod;
	}
	cout<<jc[n]%mod;
	return 0;
}

