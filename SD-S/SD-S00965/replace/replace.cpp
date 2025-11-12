#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,q;
map<string,string> mp;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<x.size();i++){
			if(a[i]!='a'&&a[i]!='b'){
				while(q--)cout<<"0\n";
				return 0;
			}
			if(b[i]!='a'&&b[i]!='b'){
				while(q--)cout<<"0\n";
				return 0;
			}
		}
		mp[a]=b;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

