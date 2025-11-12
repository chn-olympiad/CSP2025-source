#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
const ll N=1e5+5;
pair<ll,ll>e[N],d[N],f[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	return a.first-a.second<b.first-b.second;
}
void solve(){
	ll n;
	cin>>n;
	ll to1=0,to2=0,to3=0;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		ans+=max(a,max(b,c));
		if(a>=b&&a>=c)
			e[++to1]=make_pair(a,max(b,c));
		else if(b>=a&&b>=c)
			d[++to2]=make_pair(b,max(a,c));
		else f[++to3]=make_pair(c,max(a,b));
	}
//	cout<<to1<<" "<<to2<<" "<<to3<<'\n';
	if(to1>n/2){
		sort(e+1,e+1+to1,cmp);
		ll p=to1-n/2;
		for(ll i=1;i<=p;i++)ans+=(e[i].second-e[i].first);
	}else if(to2>n/2){
		sort(d+1,d+1+to2,cmp);
		ll p=to2-n/2;
		for(ll i=1;i<=p;i++)ans+=(d[i].second-d[i].first);
	}else if(to3>n/2){
		sort(f+1,f+1+to3,cmp);
		ll p=to3-n/2;
		for(ll i=1;i<=p;i++)ans+=(f[i].second-f[i].first);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>T;
	while(T--)solve();
	return 0;
} 
