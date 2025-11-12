#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=520;
const ll mod=998244353;
ll c[N];
ll a[N];
ll vis[N];
ll god;
string s;
ll n,m;
void dfs(ll p,ll cnt,ll died){
	if(p>=n){
		if(cnt>=m){
			god++;
			god%=mod;
		}
		return;
	}
	if(a[p]==0) died++;
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(c[i]<=died) dfs(p+1,cnt,died);
		else if(a[p]==0) dfs(p+1,cnt,died);
		else dfs(p+1,cnt+1,died);
		vis[i]=0;
	} 
}
void solve(){
	cin>>s;
	for(ll i=0;i<n;i++){
		a[i]=s[i]-'0';
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0,0);
	cout<<god;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=18){
		solve();
		return 0;
	}
	ll nt=n;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			nt--;
		}
	}
	if(nt<m){
		cout<<0;
		return 0;
	}
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
} 

//20-30pts
