#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const ll N=2e5+5,Q=2e5+5;
ll n,q;
string s[N][2],t[Q][2];
bool cmper(const string &a,ll x,const string &b,ll y,ll k){
	for(ll i=0;i<k;i++)
		if(a[x+i]!=b[y+i])
			return false;
	return true;
}
void solve(ll x){
	ll ans=0;
	for(ll i=0;i<t[x][0].length();i++){
		if(i>0&&t[x][0][i-1]!=t[x][1][i-1])break;
		ll c=t[x][1].length()-t[x][0].length();
		for(ll j=0;j<n;j++){
			ll a=s[j][0].length(),b=s[j][1].length();
			if(b-a!=c)continue;
			if(!cmper(t[x][0],i+a,t[x][1],i+b,t[x][0].length()-a))continue;
			if(!cmper(t[x][0],i,s[j][0],0,a))continue;
			if(!cmper(t[x][1],i,s[j][1],0,b))continue;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(ll i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(ll i=1;i<=q;i++)solve(i);
	return 0;
} 
