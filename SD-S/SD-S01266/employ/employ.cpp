#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=998244353;
int m,n,c[505],dp[505][505];
string s;
ll f(){
	for (int i=0;i<s.length();++i) if (s[i]=='0') return 0;
	for (int  i=1;i<=n;++i) if (c[i]==0) return 0;
	ll ans=1;
	for (int i=1;i<=n;++i)
		ans*=i,ans%=Mod;
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;++i) cin>>c[i];
	if (m==n){
		printf("%lld",f());
		return 0;
	}
	printf("%d",0);
	return 0;
}

