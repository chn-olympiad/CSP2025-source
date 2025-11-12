#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505;
const ll mod=998244353;
ll n,m;
string s;
ll a[N];
bool check(){
	ll num=0,cnt=0;
	for(ll i=1;i<=n;i++){
		if(num>=a[i]){
			num++;
			continue;
		}
		if(s[i]=='0'){
			num++;
			continue;
		}
		cnt++;
		if(cnt>=m) return 1;
	}
	return (cnt>=m);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll sum=1;
	for(ll i=n;i>=1;i--) sum*=i;
	ll ans=0;
	if(check()) ans++;
	for(ll i=1;i<sum;i++){
		next_permutation(a+1,a+n+1);
		if(check()) ans++;
	}
	cout<<ans<<'\n';
	return 0;
} 
