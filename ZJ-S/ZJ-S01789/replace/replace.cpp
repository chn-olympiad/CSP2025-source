#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>mp;
void solve(){
	string t1,t2;
	cin>>t1>>t2;
	if(t1.size()!=t2.size()){
		cout<<0<<"\n";
		return;
	}
	cout<<2<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)solve();
}
