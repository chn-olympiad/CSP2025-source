#include<bits/stdc++.h>
using namespace std;
int ans,n,q,r,mm[1005][1005];
string s,t;
map<string,string>mp;
map<string,int>k;
void dfs(string a,string b,string c,string d){
	if(!k[a])k[a]=++r;
	int aa=k[a];
	if(!k[b])k[b]=++r;
	int bb=k[b];
	if(mm[aa][bb])return;
	mm[aa][bb]=1;
	if(a+mp[c]+b==d)ans++;
	if(a+c[0]==d.substr(0,a.size()+1))dfs(a+c[0],b,c.substr(1,c.size()-1),d);
	if(c[c.size()-1]+b==d.substr(d.size()-b.size()-1,b.size()+1))dfs(a,c[c.size()-1]+b,c.substr(0,c.size()-1),d);
}int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s>>t;
		mp[s]=t;
		mp[t]=s;
	}for(int i=1; i<=q; i++){
		k.clear();
		cin>>s>>t;
		string g="";
		ans=0;
		dfs(g,g,s,t);
		cout<<ans<<'\n';
	}return 0;
}