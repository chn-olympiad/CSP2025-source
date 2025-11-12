#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_set<string> s;
unordered_map<string,string> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string s1,s2;
		cin>>s1>>s2;
		s.insert(s1);
		m[s1]=s2;
	}
	while(q--) {
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()) {
			cout<<0<<endl;
			continue;
		}
		int res=0;
		for(int i=0; i<s1.length(); i++) {
			string stmp="";
			for(int j=i; j<s1.length(); j++) {
				stmp+=s1[j];
				if(s.count(stmp)) {
					string sto=m[stmp];
					string snow="";
					for(int k=i; k<=j; k++) {
						snow+=s2[k];
					}
					if(sto==snow) {
						bool ok=true;					
						for(int k=0; k<s1.length(); k++) {
							if(!(k>=i&&k<=j)) {
								if(s1[k]!=s2[k]) {
									ok=false;
									break;
								}
							}
						}
						if(ok) res++;
					}
				}
			}
		}
		cout<<res<<endl;
	}
}


