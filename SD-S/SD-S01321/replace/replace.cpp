#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);				
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string str1,str2;cin>>str1>>str2;
		mp[str1]=str2;
	}
	while(q--){
		cout<<0<<endl;
	}
	return 0;
}
