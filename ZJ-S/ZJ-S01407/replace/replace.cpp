#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a[200005][5];
string s[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(n>100){
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<s[i][1].size();j++){
				if(s[i][1][j]=='b'){
					a[i][1]=j;
					break;
				}
			}
			for(ll j=0;j<s[i][2].size();j++){
				if(s[i][2][j]=='b'){
					a[i][2]=j;
					break;
				}
			}
		}
		for(ll i=1;i<=q;i++){
			ll ans=0,b=0,c=0;
			string l,r;
			cin>>l>>r;
			for(ll j=0;j<l.size();j++){
				if(l[j]=='b'){
					b=j;
				}
				if(r[j]=='b'){
					c=j;
				}
			}
			for(ll j=1;j<=n;j++){
				if(a[j][1]-a[j][2]==b-c&&a[j][1]<=b&&s[j][1].size()-a[j][1]<=l.size()-b){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(ll ii=1;ii<=q;ii++){
		ll ans=0;
		string l,r;
		cin>>l>>r;
		for(ll i=0;i<l.size();i++){
			for(ll j=1;j<=n;j++){
				if(s[j][1].size()+i<=l.size()){
					ll g=0;
					for(ll x=i;x<i+s[j][1].size();x++){
						if(l[x]!=s[j][1][x-i]){
							g++;
							break;
						}
					}
					if(g){
						continue;
					}
					bool flag=0;
					for(ll x=0;x<i;x++){
						if(l[x]!=r[x]){
							flag=1;
							break;
						}
					}
					for(ll x=i;x<s[j][2].size()+i;x++){
						if(s[j][2][x-i]!=r[x]){
							flag=1;
							break;
						}
					}
					for(ll x=i+s[j][1].size();x<l.size();x++){
						if(l[x]!=r[x]){
							flag=1;
							break;
						}
					}
					if(!flag){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}