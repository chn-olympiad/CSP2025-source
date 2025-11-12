#include<bits/stdc++.h>
using namespace std;
string re1[200005];
string re2[200005];
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>re1[i]>>re2[i];
	}
	string s1,s2;
	while(q--) {
		int vis[200005];
		cin>>s1>>s2;
		int ans=0;
		string ns1=s1;
		string ns2=s2;
		for(int i=1; i<=n; i++) {
			int flag=1;
			if(vis[i]!=1){
				if(ns1==ns2) {
					ns1=s1;
					ns2=s2;
					ans++;
					i=1;
					continue;
				}
				int xb1=ns1.find(re1[i]);
				int xb2=ns2.find(re2[i]);
				if(xb1==-1||xb2==-1) {
					continue;
				}
				if(xb1==xb2) {
					for(int j=xb1; j<re1[i].size()+xb1; j++) {
						ns1[j]='*';
						ns2[j]='*';
						vis[i]=1;
					}
				} else {
					for(int j=xb1; j<re1[i].size()+xb1; j++) {
						if(ns1[j]==ns2[j]) {
							ns1[j]='*';
							ns2[j]='*';
						} else {
							continue;
						}

					}
				}

			}
		}
		cout<<ans<<"\n";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;


}
