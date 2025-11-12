#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200200],s2[200200],s,t;
vector<int>find(int x){
	vector<int>vec;
	if(s.size()>=s1[x].size()){
		for(int i=0;i<=s.size()-s1[x].size();i++){
			if(s[i]==s1[x][0]){
				for(int j=1;j<s1[x].size();j++){
					if(s[i+j]!=s1[x][j]){
						break;
					}
				}
				vec.push_back(i);
			}
		}
	}
	return vec;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>s>>t;
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<int>vec=find(i);
			if(!vec.empty()){
				for(int j=0;j<vec.size();j++){
					string tmp=s.substr(0,vec[j])+s2[i]+s.substr(vec[j]+s2[i].size());
					if(tmp==t){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
