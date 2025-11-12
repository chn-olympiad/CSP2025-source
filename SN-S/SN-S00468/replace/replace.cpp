#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200003][2];
map<pair<string,string>,int>mp;
signed main(){
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1],mp[{s[i][0],s[i][1]}]++;
	int tot=0;
	for(auto tmp:mp){
		s[++tot][0]=tmp.first.first,s[tot][1]=tmp.first.second;
	}
	n=tot;
	while(q--){
		string a,b;cin>>a>>b;
		int ans=0,l=0,r=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i])r=i;
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]!=b[i])l=i;
		}
		string a1=a.substr(l,r-l+1),b1=b.substr(l,r-l+1);
		for(int i=1;i<=n;i++){
			if(a.size()<s[i][0].size())continue;
			int ll=0,rr=0;
			for(int j=0;j<s[i][0].size();j++)
				if(s[i][0][j]!=s[i][1][j])rr=j;
				
			for(int j=s[i][0].size()-1;j>=0;j--)
				if(s[i][0][j]!=s[i][1][j])ll=j;
				
			string c=s[i][0].substr(ll,rr-ll+1),d=s[i][1].substr(ll,rr-ll+1);
			if(a1!=c || b1!=d)continue;
			
			for(int j=1;ll-j>=0;j++)if(s[i][0][ll-j]!=a[l-j])continue;
			for(int j=1;rr+j<s[i][0].size();j++)if(s[i][0][rr+j]!=a[r+j])continue;
			ans++;
		}
		cout<<ans<<'\n';
	}
   return 0;
}

