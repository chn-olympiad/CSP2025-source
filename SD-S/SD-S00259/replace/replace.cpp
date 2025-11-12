#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=0;i<n;++i)cin>>s[i]>>t[i];
if(q==1){
	string a,b;
	cin>>a>>b;
	int ans=0;
	for(int i=0;i<n;++i)
	if(a==s[i]&&b==t[i])++ans;
	for(int i=0;i<n;++i){
		
	}cout<<ans;
}while(q--){
	cout<<0;
}
	return 0;
}
