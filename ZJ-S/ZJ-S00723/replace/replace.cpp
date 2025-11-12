#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[1005][3],s2[1005][3];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1[i][1];
		cin>>s1[i][2];
	}
	for(int i=1; i<=q; i++) {
		cin>>s2[i][1]>>s2[i][2];
	}
	for(int i=1; i<=q; i++) {
		int ans=0;
		if(s2[i][1].size()!=s2[i][2].size()) {
			cout<<0<<endl;
			continue;
		}
		bool flag=false;
		for(int j=1; j<=n; j++) {
			flag=false;
			for(int l=0; l<=s2[i][1].size()-s1[j][1].size(); l++) {
//				cout<<8888<<endl;
				flag=false;
				for(int k=l; k<=l+s1[j][1].size()-1; k++) {
					if(s2[i][1][k]!=s1[j][1][k-l]) {
						flag=true;
						break;
					}
				}
//				cout<<8888<<endl;
				if(flag) continue;
				bool flag2=true;
				for(int k=0; k<s2[i][1].size(); k++) {
					
					if(k>=l and k<=l+s1[j][1].size()-1) {
						if(s1[j][2][k-l]!=s2[i][2][k]) {
							flag2=false;
							break;
						}
					} else {
						if(s2[i][1][k]!=s2[i][2][k]) {
							flag2=false;
							break;
						}
					}
				}
				if(flag2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

