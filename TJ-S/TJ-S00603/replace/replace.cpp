#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
pair<string,string> s[200005];
bool fun(string a,string b,string s,string t){
	for(int i=0;i+s.size()-1<a.size();i++)
		if(a.substr(i,s.size())==s){
			string tmp=a.substr(0,i)+t+a.substr(i+s.size());
			if(tmp==b)return 1; 
		}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].first>>s[i].second;
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=fun(a,b,s[i].first,s[i].second);
		cout<<ans<<endl;
	}
	return 0;
}

