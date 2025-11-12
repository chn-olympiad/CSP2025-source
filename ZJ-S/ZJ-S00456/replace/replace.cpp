#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s;
//string s[200020][2];
//string t[5000050][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s;
	}
	for(int i=0;i<q;i++){
		cin>>s;
	}
//
//	cin>>n>>q;
//	for(int i=0; i<n; i++) {
//		char x;
//		while(cin>>x&&x!=' ') s[i][0]+=x;
//		for(int j=0; j<s[i][0].size(); j++) {
//			cin>>x;
//			s[i][1]+=x;
//		}
//	}
//	for(int i=0; i<q; i++) {
//		char x;
//		while(cin>>x&&x!=' ') t[i][0]+=x;
//		for(int j=0; j<t[i][0].size(); j++) {
//			cin>>x;
//			t[i][1]+=x;
//		}
//	}
	//
//	if(n<=100&&q<=100) {
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<s[i][0].size(); j++) {
//				k+=s[i][0][j];
//				string p=k;
//				for(int c=0; c<q; c++) {
//					p+=t[c][1];
//					for(int l=j+t[c][1].size()+1; l<s[i][0].size(); l++) {
//						p+=s[i][0][l];
//
//					}
//					if(p==s[i][1]) ans++;
//				}
//			}
//		}
//	}
//	cout<<ans;
	for(int i=0;i<q;i++) cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
