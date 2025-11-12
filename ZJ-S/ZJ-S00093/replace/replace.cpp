#include<bits/stdc++.h>
using namespace std;
#define IO(fn) freopen(fn".in","r",stdin);freopen(fn".out","w",stdout);
typedef long long ll;
const ll N=2e5+25;
pair<string,string> s[N],t[N];
#define fi first
#define sc second
int main(){IO("replace");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].fi>>s[i].sc;
	}
	int ans;
	for(int i=1;i<=m;i++){
		ans=0;
		cin>>t[i].fi>>t[i].sc;
		for(int j=1;j<=n;j++){
			int l=s[j].fi.size();
			if(l>t[i].fi.size())continue;
			for(int p=0;p<=t[i].fi.size()-l;p++){
				if(t[i].fi.substr(p,l)==s[j].fi){
//					cerr<<t[i].fi.substr(p,l)<<'\n';
					string tmp=t[i].fi.substr(0,p)+s[j].sc+t[i].fi.substr(p+l,t[i].fi.size()-p-l);
//					cerr<<tmp<<'\n';
					if(tmp==t[i].sc){
//						cerr<<"+1\n";
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
