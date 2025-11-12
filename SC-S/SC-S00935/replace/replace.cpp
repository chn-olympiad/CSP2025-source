#include<bits/stdc++.h>
using namespace std;

int n,q;
unordered_map<string,string> h;
unordered_map<int,string> ha;
string a,b;
string co;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; ++i) {
		string x,y;
		cin>>x>>y;
		h[x]=y; 
		ha[i]=x;
	}
	while(q--) {
		int ans=0;
		cin>>a>>b;
		for(int i=1; i<=n; ++i) {
			int len=ha[i].size();
			if(len>a.size()) continue;
			for(int j=0; j<=a.size()-len; ++j) {
				co.erase();
				for(int k=j; k<=j+len-1; ++k) {
					co+=a[k];
				}
				if(co==ha[i]) {
					co.erase();
					for(int k=0; k<j; ++k)  {
						if(j==0) break;
						co+=a[k];
					}
					co+=h[ha[i]];
					for(int k=j+len; k<a.size(); ++k) if(k<a.size()) co+=a[k];
				}
				if(co==b) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 