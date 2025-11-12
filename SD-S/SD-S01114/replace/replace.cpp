#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1; i<=q; i++) {
		string t1,t2;
		cin>>t1>>t2;
		if(n<=100) {
			int ans=0;
			for(int i=1; i<=n; i++) {
				int p1=t1.find(s[i][0]);
				int p2=t2.find(s[i][1]);
				if(p1==p2 && p1>=0 && p1<t1.size()) {
					bool f=1;
					for(int j=0; j<p1; j++) {
						f&=(t1[j]==t2[j]);
					}
					for(int j=p1+s[i][0].size(); j<t1.size(); j++) {
						f&=(t1[j]==t2[j]);
					}
					ans+=f;
				}
			}
			cout<<ans<<'\n';
		} else {
			cout<<"0\n";
		}
	}
	return 0;
}
