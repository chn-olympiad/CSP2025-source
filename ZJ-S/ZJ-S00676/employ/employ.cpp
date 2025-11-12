#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=998244353;
int n,m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%mod;
	}
	cout<<(ans%mod);
	return 0;
}
