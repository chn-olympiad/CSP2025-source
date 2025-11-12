#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e5+10;
string s;
vector<ll>g;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')g.push_back(s[i]-'0');
	}
	sort(g.begin(),g.end());
	for(ll i=g.size()-1;i>=0;i--){
		cout<<g[i];
	}
	return 0;
}
