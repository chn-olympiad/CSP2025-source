#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<string,string> m;
	for(int i=1; i<=n; i++) {
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1; i<=q; i++) {
		string s,t,s1=s;
		cin>>s>>t;
		int ans=0;
		for(int i=0; i<s.size(); i++) {
			for(int j=0; j<=i; j++) {
				string tmp=s.substr(j,i-j+1);
				if(m[tmp]!="") {
					for(int k=j; k<=i; k++) {
						s1[k]=m[tmp][k-j];
					}
					if(s1==t){
						ans++;
					}
					s1=s;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
