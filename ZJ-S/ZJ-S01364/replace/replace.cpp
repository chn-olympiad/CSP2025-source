//25pts
#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,q;
unordered_map<string,string>mp;
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		ans=0;
		int k=s.size();
		string x="";
		for(register int i=0;i<k;++i){
			if(i)x.push_back(s[i-1]);
			for(register int j=i;j<k;++j){
				string p=s.substr(i,j-i+1);
				if(mp.find(p)!=mp.end()){
					string y=mp[p],z="";
					if(j<k-1)z=s.substr(j+1,k-1-j);
					if(x+y+z==t)++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
