#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int l[1000050];
int r[1000050];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int q=1;q<=m;q++){
		int ans=0;
		string s,t;
		int f=0;
		int cnt=0;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<'\n';
			continue;
		}
		l[0]=q;r[s.size()-1]=q;
		for(int i=1;i<s.size();i++){
			if(l[i-1]!=q) continue;
			else if(s[i-1]==t[i-1]){
				l[i]=q;
			}
		}
		for(int i=s.size()-2;i>=0;i--){
			if(r[i+1]!=q) continue;
			else if(s[i+1]==t[i+1]){
				r[i]=q;
			}
		}
		for(int i=0;i<s.size();i++){
			string zc="";
			string mb="";
			if(l[i]!=q) continue;
			for(int j=i;j<s.size();j++){
				zc+=s[j];
				mb+=t[j];
				if(r[j]!=q) continue;
				string nc=mp[zc];
				if(mb==nc) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//10