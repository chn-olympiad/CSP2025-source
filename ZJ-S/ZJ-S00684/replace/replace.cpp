#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0x3f3f3f3f;
map<string,string> mp;
string s,s1,s2;
void dfs(int step){
	if(s==s2){
		ans=min(step,ans);
		return;
	}
	for(int l=0;l<s.size();l++){
		for(int r=l;r<s.size();r++){
			string tool1=s.substr(l,r)
			if(mp[tool1]!="\0"){
				for(int i=l,i<=r;i++){
					s[i]=mp[tool2][i-l];
				}
			}
		}
	}
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		dfs(s1);
		cout<<ans<<"\n";
		ans=0x3f3f3f3f;
	}

	return 0;
}

