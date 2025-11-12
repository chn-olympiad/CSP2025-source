#include<bits/stdc++.h>
using namespace std;//A
const int maxn=505,mod=998244353;
int n,m,c[maxn];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		ans=1ll*ans*i%mod;
	}
	cout<<ans;
	return 0;
}

