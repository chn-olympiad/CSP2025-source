#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
vector<ll>adj;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();++i){
		if(s[i]-'0'>=0*1LL&&s[i]-'0'<=9*1LL){
			adj.push_back(s[i]-'0');
		}
	}
	sort(adj.begin(),adj.end(),greater<ll>());
	for(ll i=0;i<adj.size();++i){
		cout<<adj[i];
	}
	return 0;
}
