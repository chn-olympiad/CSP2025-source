#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
typedef long long ll;
typedef double ld;
using namespace std;
const ll N=5e2+5,mod=998244353,inf=2e18;
const ld eps=1e-6;
ll n,m,a[N],ans,vis[N],bis[N];
string s;
void dfs(ll x) {
	if(x==n+1) {
		ll cnt=0,lt=1;
		for(ll i=1;i<=n;i++) {
//			while(lt-1-cnt>=a[vis[lt]]&&lt<=n) {
//				lt++;
//			}
//			if(lt>n) {
//				break;
//			}
//			if(s[i]=='1') {
//				cnt++;
//			}
			if(i-1-cnt>=a[vis[i]]) {
				continue;
			}
			if(s[i]=='1') {
				cnt++;
			}
		}
		ans+=(cnt>=m);
		ans%=mod;
		return ;
	}
	for(ll i=1;i<=n;i++) {
		if(bis[i]) {
			continue;
		}
		bis[i]=1;
		vis[x]=i;
		dfs(x+1);
		bis[i]=0;
		vis[x]=0;
	}
}
inline void solve() {
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++) {
		cin>>a[i];
	}
	s=" "+s;
	if(n>11) {
		sort(a+1,a+1+n);
		ll cnt=0;
		for(ll i=1;i<=n;i++) {
			if(i-1-cnt>=a[i]) {
				continue;
			}
			cnt+=(s[i]=='1');
		}
		if(cnt<m) {
			cout<<0;
			return ;
		}
		cout<<((1<<n)%mod);
		return ;
	}
	dfs(1);
	cout<<ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}