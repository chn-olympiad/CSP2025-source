#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,mod=998244353;
ll n,m,ans=1;
ll s[N];
ll c[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n;i>=1;i--) {
		ans=((ans%mod)*(i%mod))%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
