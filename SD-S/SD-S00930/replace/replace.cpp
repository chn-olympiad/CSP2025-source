#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n,t,ans;
vector<string> s1s,s2s;
bool check(string s,string x,int idx){
	int i=idx,j=0;
	for(;i<idx+x.size()&&j<x.size();i++,j++)
		if(s[i]!=x[j])return false;
	return true;
}
void dfs(string s1,string s2){
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=0;j+s1s[i].length()<s1.size();j++){
			if(check(s1,s1s[i],i)){
				flag=true;
				for(int k=i,h=0;k<s2s[i].size()+i&&h<s2s[i].size();k++,h++)s1[k]=s2s[i];
				if(s1==s2){
					ans++;
					return;
				}
				dfs(s1,s2);
			}
		}
	}
	if(!flag&&s1==s2)ans++;
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>t;
	s1s.resize(n+1);
	s2s.resize(n+1);
	for(int i=1;i<=n;i++)cin>>s1s[i]>>s2s[i];
	while(t--){
		string s1,s2;
		ans=0;
		dfs(s1,s2);
		cout<<ans<<endl;
	}
	return 0;
}
