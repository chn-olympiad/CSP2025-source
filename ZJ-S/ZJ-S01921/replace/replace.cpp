#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,q,ans;
string s,t;
map<string,vector<string> >mp;
map<pair<string,int>,bool> vis;
map<string,bool> vis2;
bool viss[5005];
void dfs(int x,string ss,string tt){
	if(x==s.size()+1){
	//	cout<<"+++ "<<ss<<' '<<tt<<endl;
		tt+=ss;
	//	cout<<"+++ "<<ss<<' '<<tt<<endl;
		if(tt==t)
			ans++;
		return;
	}
	for(int i=0;i<mp[ss].size();i++)
		if(mp[ss][i]!=""&&(!vis[make_pair(ss,i)]&&!viss[x])){
			vis[make_pair(ss,i)]=1;viss[x]=1;
			dfs(x+1,"",tt+mp[ss][i]);
			vis[make_pair(ss,i)]=0;viss[x]=0;
		}
	dfs(x+1,ss+s[x],tt);
	dfs(x+1,"",tt+ss+s[x]);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>s>>t,mp[s].push_back(t),mp[t].push_back(s);
	while(q--){
		ans=0;
		cin>>s>>t;
		dfs(0,"","");
		cout<<ans<<endl;
	}
}/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

ab ba
abaa baaa

*/
