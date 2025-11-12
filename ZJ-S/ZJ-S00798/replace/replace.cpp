#include <bits/stdc++.h>
using namespace std;
string s1,s2;
map<string,string> mp;
int ans,n,T;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(T--){
		cin>>s1>>s2;
		ans=0;
		if(mp[s1]==s2||mp[s2]==s1){
			for(int i=0;i<s1.size();i++)
				if(s1[i]!=s2[i]) ans++;
			cout<<ans<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}
