#include<bits/stdc++.h>
using namespace std;
string a[200010][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i][0]>>a[i][1];
	}
	for(int w=1; w<=q; w++) {
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			cout<<0<<"\n";
			continue;
		}
		int l=2e9,r=0;
		for(int i=0; i<=t1.size(); i++) {
			if(t1[i]!=t2[i]) {
				l=min(l,i);
				r=max(r,i);
			}
		}
		int ans=0;
		for(int ll=0; ll<=l; ll++) {
			string s1,s2;
			for(int i=ll; i<r; i++) {
				s1+=t1[i];
				s2+=t2[i];
			}
			for(int rr=r; rr<t1.size(); rr++) {
				s1=s1+t1[rr];
				s2=s2+t2[rr];
				for(int j=1; j<=n; j++) {
					if(s1==a[j][0]&&s2==a[j][1]) {
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
