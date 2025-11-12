#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[200010],t[200010],a[200010],b[200010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i = 1; i<=n; i++) {
		cin>>s[i]>>t[i];
	}
	for(int o = 1; o<=q; o++) {
		cin>>a[o]>>b[o];
		long long ans = 0;
		for(int i = 1; i<=n; i++) {
			for(int j = 0; j<(a[o].size()); j++) {
				if(j+(int)s[i].size()-1>=a[o].size()){
					continue;
				}
				string u = "";
				for(int k = j; k<=j+(int)s[i].size()-1; k++) {
					u+=a[o][k];
				}
				if(s[i]==u) {
					string a2 = a[i];
					for(int k = j; k<=j+(int)s[i].size()-1; k++) {
						a[o][k] = t[i][k-j];
					}
					if(a[o]==b[o]) ans++;
					for(int k = j; k<=j+(int)s[i].size()-1; k++) {
						a[o][k] = s[i][k-j];
					}					
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
