#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,l;
string s[200005],t[200005],a,b;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s[i]>>t[i];
	while(q--) {
		int ans=0,ll=0,rr=0;
		cin>>a>>b;
		if(a.size()!=b.size()) {
			cout<<0<<"\n";
			continue;
		}
		a=" "+a,b=" "+b,l=a.size()-1;
		for(int i=1; i<=l; i++)
			if(a[i]!=b[i]) {
				ll=i;
				break;
			}
		for(int i=1; i<=l; i++)
			if(a[i]!=b[i])rr=i;
		for(int i=1; i<=n; i++) {
			int x=a.find(s[i]);
			int y=b.find(t[i]);
			if(x==-1||y==-1)continue;
			if(x!=y)continue;
			int li=x,ri=x+s[i].size()-1;
			if(li<=ll&&ri>=rr)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//csprp++;
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/