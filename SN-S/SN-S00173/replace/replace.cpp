#include<bits/stdc++.h>
#define pss pair<string,string>
using namespace std;
string s,t;
pss ch[200005];
int n,q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>ch[i].first>>ch[i].second;
	}
	if(q==1) {
		int ans=0;
		string ls;
		cin>>ls>>t;
		if(ls.size()!=t.size()) {
			cout<<0<<"ss\n";
		}
		s=ls;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=s.size()-ch[i].first.size(); j++) {
				for(int k=j; k<=ch[i].first.size(); k++) {
					if(s[k]!=ch[i].first[k-j]) {
						break;
					} else {
						s[k]=ch[i].second[k-j];
					}
				}
				if(s==t)ans++;
				s=ls;
			}
		}
		cout<<ans;
		return 0;
	}
	while(q--) {
		cin>>s>>t;
		if(s.size()!=t.size()) {
			cout<<0<<"\n";
		} else {
			int fg=0;
			for(int i=1; i<=s.size(); i++) {
				if(s[i]==t[i]) {
					if(fg%2==0) {
						s.erase(i);
						t.erase(i);
					}
				} else {
					fg++;
				}
			}
			for(int j=1; j<=n; j++) {
				for(int i=1; i<=ch[j].first.size(); i++) {
					if(ch[j].first[i]==ch[j].second[i]) {
						if(fg%2==0) {
							ch[j].first.erase(i);
							ch[j].second.erase(i);
						}
					} else {
						fg++;
					}
				}
			}
			int ans=0;
			for(int i=1; i<=n; i++) {
				if(ch[i].first==s and ch[i].second==t) {
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
3 1
a b
b c
c d
aa bb
*/
