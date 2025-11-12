#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
unordered_map<string,string>mp;
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>x>>y;
		mp[x]=y;
	}
	for(ll i=1;i<=q;i++){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
		}
		ll ans=0,sz=x.size();
		x=' '+x,y=' '+y;
		ll dl=0,dr=0;
		for(ll l=1;l<=sz;l++){
			if(x[l]!=y[l]){
				dl=l;
				break;
			}
		}
		for(ll r=sz;r>=dl;r--){
			if(x[r]!=y[r]){
				dr=r;
				break;
			}
		}
		for(ll l=1;l<=dl;l++){
			string s(x.begin()+l,x.begin()+dr-1),t(y.begin()+l,y.begin()+dr-1);
			for(ll r=max(l,dr);r<=sz;r++){
				s+=x[r],t+=y[r];
				ans+=(mp[s]==t);
			}
		}
		cout<<ans<<endl;
	}
}

