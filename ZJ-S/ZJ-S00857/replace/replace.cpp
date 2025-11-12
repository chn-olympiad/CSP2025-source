#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,cnt,ans;
string s,ss;
map<string,int> mp;
map<int,string> its;
vector<int> g[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>ss;
		if(!mp[s]){
			mp[s]=++cnt;
			its[cnt]=s;
		}
		if(!mp[ss]){
			mp[ss]=++cnt;
			its[cnt]=ss;
		}
		g[mp[s]].push_back(mp[ss]);
	}
	while(q--){
		ans=0;
		cin>>s>>ss;
		if(s.size()!=ss.size()){
			cout<<"0"<<endl;
			continue;
		}
		for(int i=0;i<=s.size();i++){
			for(int j=0;j<=s.size();j++){
				if(i+j>=s.size()){
					break;
				}
				int l=s.size()-i-j;
				string x=s.substr(0,i);
				string y=s.substr(i,l);
				string z=s.substr(i+l,j);
				if(mp[y]){
					for(int k=0;k<g[mp[y]].size();k++){
						string t=its[g[mp[y]][k]];
						string tt=x;
						tt+=t;
						tt+=z;
						if(tt==ss){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}