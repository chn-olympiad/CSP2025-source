#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
typedef long long ll;
typedef string sig;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<vel> vevel;
typedef vector<pll> velp;
void slv(){
	ll n,q;
	cin>>n>>q;
	map<sig,sig> mp;
	for(int i=1;i<=n;i++){
		sig s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		sig s1,s2;
		cin>>s1>>s2;
		ll len=s1.size();
		s1=' '+s1;
		s2=' '+s2;
		ll lx=n+1,rx=0;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				lx=i;
				break;
			}
		}
		for(int i=len;i>=1;i--){
			if(s1[i]!=s2[i]){
				rx=i;
				break;
			}
		}
		ll ans=0;
		for(auto i:mp){
			ll ilen=i.ft.size();
			for(int j=1;j+ilen-1<=len;j++){
				bool b=1;
				for(int k=j;k<=j+ilen-1;k++){
					if(s1[k]!=i.ft[k-j]||s2[k]!=i.sd[k-j]){
						b=0;
						break;
					}
				}
				if(b==1&&j<=lx&&j+ilen-1>=rx){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}