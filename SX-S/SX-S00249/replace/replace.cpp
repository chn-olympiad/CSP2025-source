#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][3];
string t[200010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}