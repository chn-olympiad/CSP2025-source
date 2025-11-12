#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],s2[200005],t,t2;
void solve(){
	cin>>t>>t2;
	if(t.size()!=t2.size()){
		cout<<0<<'\n';
		return;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}
	while(q--){
		solve();
	}
	return 0;
}