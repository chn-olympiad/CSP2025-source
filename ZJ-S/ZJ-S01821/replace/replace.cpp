#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll n, q;
map<pair<string, string>, bool>mp;
//ll fast_h(string s){
//	ll sum=0;
//	for(ll i=0; i<s.size(); i++)sum*=26, sum+=s[i]-'a', sum=sum%m;
//	return sum;
//}
void solve(){
	ll sum=0;
	string s, str;cin >> s >> str;
	string chans="", chast="";ll l=-1, r=-1;
	for(ll i=0; i<s.size(); i++){
		if(s[i]!=str[i]){
			if(l==-1)l=i;
			if((r==-1||r!= (r-1) )==0){
				cout<<"0\n";
				return;
			}
			r=i;
			chans+=s[i], chast+=str[i];
		}
	}
	sum+=mp[{chans, chast}];
//	cout<<chans<<','<<chast<<'\n';
	string sl="";
	for(ll il=l-1; il>=0; il--){
		string sr="";
		for(ll ir=r+1; ir<s.size(); ir++){
			sr+=s[ir];
//			cout<<sl+chans+sr<<','<<sl+chast+sr<<'\n';
			sum+=mp[{sl+chans+sr, sl+chast+sr}];
		}
		sl=s[il]+sl;
	}
	string sr="";
	for(ll ir=r+1; ir<s.size(); ir++){
		sr+=s[ir];
//		cout<<sl+chans+sr<<','<<sl+chast+sr<<'\n';
		sum+=mp[{sl+chans+sr, sl+chast+sr}];
	}
	cout<<sum<<'\n';
	return;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(ll i=1; i<=n; i++){
		string s, str;cin >> s >> str;
		mp[{s, str}]=1;
	}
	while(q--){
		solve();
	}
	return 0;
}

