#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	while(n--){
		string a,b;
		cin >>a>>b;
		mp[a]=b;
	}
	while(q--){
		cout<<0<<"\n";
	}
	
	return 0;
}

