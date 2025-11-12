#include <bits/stdc++.h>
using namespace std;
map<string,string> rule;
string ori,tgt;
int n,q;
int ans;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		string u,v;
		cin>>u>>v;
		rule[u] = v;
	}
	
	while(q--) {
		ans=0;
		cin>>ori>>tgt;
		for(auto p : rule) {
			int x = ori.find(p.first);
			if(x < (int)ori.size() && x>=0) {
//				cout<<p.first<<" "<<x<<"\n";
				if(ori.substr(0,x) + p.second + ori.substr(x+(int)p.first.size(),(int)ori.size() - (x+(int)p.first.size())) == tgt) {
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}