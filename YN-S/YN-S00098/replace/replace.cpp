#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q; cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string s,t; cin >> s >> t;
		mp[s] = t;
	}
	while(q--){
		string u,v; cin >> u >> v;
		int ans = 0;
		for(int i = 0;i < u.size();i++){
			for(int j = i + 1;j < u.size();j++){
				if(mp.find(u.substr(i,j)) != mp.end()){
					cout << u.substr(0,i + 1) + mp[u.substr(i,j)] + u.substr(j,u.size()) << "\n";
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}