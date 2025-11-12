#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		string ai,bi;
		cin>>ai>>bi;
		mp[ai]=bi;
	}
	for (int j=1;j<=q;j++){
		string n,g;
		ans=0;
		cin>>n>>g;
		if (n.size()!=g.size()) {
			cout<<0;continue;
		}
		int len=n.size();
		int left=0,right=0;
		for (int i=0;i<len;i++){
			if (n[i]==g[i]) ++left;
			else break;
		}
		for (int i=len-1;i>=0;i++){
			if (n[i]==g[i]) ++right;
			else break;
		}
		for (int i=0;i<len;i++){
			for (auto& p:mp){
				if (mp[n.substr(i,p.first.size())]==p.second){
					if (i<=left && i+p.first.size()>=right) ++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

