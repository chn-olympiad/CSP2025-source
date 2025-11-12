#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
map<string,int>vis;
map<string,string>b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
    {
    	cin>>s1>>s2;
    	vis[s1]=1;
    	b[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) {
			cout<<0<<"\n";
			continue;
		}
		int ll,rr;
		for(int j=0;j<s2.size();j++){
			if(s1[j]!=s2[j]) {
				ll=j;break;
			}
		}
		for(int j=s2.size()-1;j>=0;j--)
			if(s1[j]!=s2[j]) {
				rr=j;break;
			}
		for(int l=ll;l>=0;l--)
		for(int r=rr;r<s2.size();r++)
		{   
			int lenn=r-l+1;
			if(vis[s1.substr(l,lenn)])
			if(b[s1.substr(l,lenn)]==s2.substr(l,lenn)) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
