#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
map<string,string> vis;
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s>>t;
		vis[s]=t;
	}
	for(long long i=1;i<=q;i++){
		cin>>s>>t;
		ans=0;
		string sl;
		for(long long x=0;x<=s.length();x++){
			if(x>0) sl+=s[x-1];
			string sm;
			for(long long y=0;y<=s.length();y++){
				if(y>x) sm+=s[y-1];
				string sr;
				for(long long i=y;i<s.length();i++){
					sr+=s[i];
				}
				string ss=sl+vis[sm]+sr;
				if(ss==t) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
