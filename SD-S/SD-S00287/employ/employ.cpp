#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505],c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=(ans%mod*i%mod)%mod;
	cout<<ans%mod;
	return 0;
}
