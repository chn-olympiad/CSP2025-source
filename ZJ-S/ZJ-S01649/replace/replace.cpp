#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
map<int,int> mp1[5000005];
int n,q,f=0,b[5000005],sum[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
		if(f==1)continue;
		int ba=0,bb=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!='a'&&a[i]!='b'||(b[i]!='a'&&b[i]!='b')){
				f=1;
				break;
			}
			if(a[i]=='b')ba=i;
			if(b[i]=='b')bb=i;
		}
		mp1[a.size()][ba-bb]++;
	}
	if(f==0){
		while(q--){
			string s,t;
			cin>>s>>t;
			int sb,tb=0;
			for(int i=0;i<s.size();i++){
				if(s[i]=='b')sb=i;
				if(t[i]=='b')tb=i;
			}
			int xb=sb-tb,sum=0;
			for(int i=1;i<=sb+1;i++){
				sum+=mp1[i][xb];
			}
			cout<<sum<<endl;
		}
		return 0;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		string ss="";
		int ans=0;
		for(int i=0;i<s.size();i++){
			string la="";
			for(int j=s.size()-1;j>=i+1;j--){
				string p=s.substr(i,j-i+1);
				if(mp[p]!=""){
					if(ss+mp[p]+la==t){
						ans++;
					}
				}
				if(s[j]!=t[j])break;
				la+=s[j];
			}
			if(s[i]!=t[i])break;
			ss+=s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}