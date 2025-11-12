#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505;
ll n,q;
map<string,string>sp;
map<string,bool>ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		sp[s1]=s2;
		ss[s1]=1;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		ll l=-1,r;
		for(ll i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		ll ans=0;
		for(ll i=0;i<=l;i++){
			for(ll j=r;j<s1.size();j++){
				string a,b,c;
				for(ll k=0;k<i;k++)a+=s1[k];
				for(ll k=i;k<=j;k++)b+=s1[k];
				for(ll k=j+1;k<s1.size();k++)c+=s1[k];
				if(ss[b]==1){
//					cout<<a<<" "<<b<<" "<<c<<" "<<sp[b]<<"\n";
					if(a+sp[b]+c==s2)++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
