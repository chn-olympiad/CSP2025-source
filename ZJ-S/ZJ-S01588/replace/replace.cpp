#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+10,M=210,mod=998244353,base=233;
ll n,q;
string s1[N],s2[N];
ll h1[N],h2[N];
ll l[N],pw[N];
ll H1[N],H2;
ll H(ll l,ll r){
	if(l>r)return 0;
	return (H1[r]-(H1[l-1]*pw[r-l+1])+mod*mod)%mod;
}
vector<ll>g[30];
signed main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    pw[0]=1;
    for(ll i=1;i<=200000;i++)pw[i]=pw[i-1]*base%mod;
    for(ll i=1;i<=n;i++){
    	cin>>s1[i]>>s2[i];
    	l[i]=s1[i].size();
    	s1[i]=" "+s1[i];
    	s2[i]=" "+s2[i];
    	ll p=0;
    	for(ll j=1;j<=l[i];j++){
    		p=p*base+s1[i][j];
    		p%=mod;
		}
		h1[i]=p;
		p=0;
		for(ll j=1;j<=l[i];j++){
    		p=p*base+s2[i][j];
    		p%=mod;
		}
		h2[i]=p;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		ll len=a.size();
		ll ans=0;
		for(ll i=0;i<26;i++)g[i].clear();
		a=" "+a;
		b=" "+b;
		for(ll i=0;i<=len;i++)H1[i]=0;
		H2=0;
		for(ll i=1;i<=len;i++){
			H1[i]=H1[i-1]*base+a[i];
			H1[i]%=mod;
			g[a[i]-'a'].push_back(i);
		}
		for(ll i=1;i<=len;i++){
			H2=H2*base+b[i];
			H2%=mod;
		}
//		for(ll i=0;i<26;i++){
//			cout<<char('a'+i)<<":";
//			for(ll j=0;j<g[i].size();j++){
//				cout<<g[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(ll i=1;i<=n;i++){
//			cout<<s1[i][0]-'a'<<endl;
			for(ll p=0;p<g[s1[i][1]-'a'].size();p++){
				ll j=g[s1[i][1]-'a'][p];
//				cout<<i<<":"<<j<<endl;
				if(j+l[i]-1>len)break;
				ll k=H(j,j+l[i]-1);
				if(k==h1[i]){
//					cout<<i<<":"<<j<<" "<<j+l[i]-1<<" ";
					ll now=(H(j+l[i],len)+(h2[i]*pw[len-(j+l[i]-1)])%mod+(H(1,j-1)*pw[len-(j-1)])%mod)%mod;
//					cout<<now<<" "<<H2<<endl;
					if(now==H2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

