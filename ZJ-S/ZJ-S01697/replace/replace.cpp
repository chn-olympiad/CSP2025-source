#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+5;
const ll M=2e6+6;
const ll MOD=998244353;
const ll base=10;
string s[N][3];
ll k[M][3];
ll g[M];
ll f[M];
ll h;
void solve(){
	f[0]=1;
	for(ll i=1;i<=M;i++){
		f[i]=f[i-1]*base%MOD;
	}
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		ll m=s[i][1].size();
		ll res=0;
		for(ll j=0;j<m;j++){
			res=res*base+(s[i][1][j]-'a');
			res%=MOD;
		}
		k[i][1]=res;
		
		m=s[i][2].size();
		res=0;
		for(ll j=0;j<m;j++){
			res=res*base+(s[i][2][j]-'a');
			res%=MOD;
		}
		k[i][2]=res;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ll m=t1.size();
		for(ll i=0;i<m;i++){
			if(i==0) g[i]=t1[i]-'a';
			else g[i]=(g[i-1]*base+(t1[i]-'a'))%MOD;
		}
		m=t2.size();
		h=0;
		for(ll i=0;i<m;i++){
			h=(h*base+(t2[i]-'a'))%MOD;
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=0;j+s[i][1].size()-1<m;j++){
				bool st=1;
				ll l=j,r=j+s[i][1].size()-1;
				for(ll k=l;k<=r;k++){
					if(t1[k]!=s[i][1][k-l]){
						st=0;
						break;
					}
				}
				if(st){
					string p=t1;
					for(ll k=l;k<=r;k++){
						t1[k]=s[i][2][k-l];
					}
					if(t1==t2){
						ans++;
					}
					t1=p;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}
