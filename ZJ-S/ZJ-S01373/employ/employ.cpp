#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=505;
const ll mod=998244353;
ll n,m;
string s;
ll c[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<endl;
	return 0;
}