#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n,m;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') p++;
	}
	if(p==s.size()){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			ans=ans*i;
			ans=(ans+998244353ll)%998244353ll;
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}