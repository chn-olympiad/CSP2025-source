#include<bits/stdc++.h>
using namespace std;
struct node {
	string s1;
	string s2;
} s[500009],t[500009];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++) cin>>s[i].s1>>s[i].s2;
	for(int i=0; i<q; i++) cin>>t[i].s1>>t[i].s2;
	for(int k=0; k<q; k++) {
		int l=0,r=t[k].s1.size();
		int ans=0;
		for(l=0; l<=t[k].s1.size(); l++) {
			for(r=t[k].s1.size()-1; r>=l; r--) {
				string ss,s2,s3,s4;
				for(int i=0; i<l; i++) s2+=t[k].s1[i];
				for(int i=l; i<=r; i++) ss+=t[k].s1[i];
				for(int i=r+1; i<t[k].s1.size(); i++) s3+=t[k].s1[i];
				for(int i=0; i<n; i++) {
					string s5=ss;
					if(ss==s[i].s1) {
						ss=s[i].s2;
						s4=s2+ss+s3;
						if(s4==t[k].s2) ans++;
					}
					ss=s5;
					s4="";
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
