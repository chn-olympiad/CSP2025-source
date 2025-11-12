#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		string t1,t2;
		int cnt=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<t1.size();i++){
			for(int j=0;j<t1.size();j++){
				string s1=t1.substr(i,j+1);
				string s2=t2.substr(i,j+1);
				if(mp[s1]==s2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
