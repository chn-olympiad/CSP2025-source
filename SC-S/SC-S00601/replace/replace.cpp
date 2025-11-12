#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,q;cin>>n>>q;
	vector<vector<string>> s(n,vector<string>(2)),x(q,vector<string>(2));
	for(ll i=0;i<n;i++)cin>>s[i][0]>>s[i][1];
	for(ll i=0;i<q&&cin>>x[i][0]>>x[i][1];i++){
		ll ans=0;
		for(ll j=0;j<n;j++)
			if(x[i][0].find(s[j][0])!=string::npos&&x[i][1].find(s[j][1])!=string::npos&&x[i][0].find(s[j][0])==x[i][1].find(s[j][1])){
				string s1,s2;
				for(ll k=0;k<x[i][0].find(s[j][0]);k++)s1+=x[i][0][k],s2+=x[i][0][k];
				for(ll k=x[i][0].find(s[j][0])+s[j][0].size();k<x[i][0].size();k++)s1+=x[i][0][k],s2+=x[i][1][k];
				if(s1==s2)ans++;
			}
		cout<<ans<<'\n';
	}
	return 0;
}