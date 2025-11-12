#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll N=262154;
constexpr ll mod=998244353;
ll n,m,p2n,a[501],b[501],f[N][19];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	if(n==m){
		for(ll i=1;i<=n;i++){
			if(!a[i]||!b[i-1]){
				cout<<"0\n";
				return 0;
			}
		}
		ll ans=1;
		for(ll i=1;i<=n;i++){
			(ans*=i)%=mod;
		}
		cout<<(ans+mod)%mod<<"\n";
		return 0;
	}
	f[0][0]=1;
	p2n=1ll<<n;
	for(ll i=0;i<p2n-1;i++){
		ll c=__builtin_popcountll(i);
		for(ll j=0;j<=c;j++){
			for(ll k=0;k<n;k++){
				if(!(i>>k&1)){
					(f[i|1ll<<k][j+(c-j<b[k]&&a[c+1])]+=f[i][j])%=mod;
				}
			}
		}
	}
	ll ans=0;
	for(ll i=m;i<=n;i++){
		(ans+=f[p2n-1][i])%=mod;
	}
	cout<<(ans+mod)%mod<<"\n";
	return 0;
}