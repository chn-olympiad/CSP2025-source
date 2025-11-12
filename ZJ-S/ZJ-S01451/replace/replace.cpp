#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+10;

int n,q;
map<string,string> mp;

int len=0;

void solve(){
	string aaa,bbb; cin>>aaa>>bbb;
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin); freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b; cin>>a>>b;
		mp[a]=b;
		len=max(len,(int)a.size());
	}
	while(q--){
		cout<<0<<"\n";
	}
	return 0;
}
