#include<bits/stdc++.h>
using namespace std;
#define int long long
string spr[200010],sne[200010];
map<string,string>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,T;
	cin >>n>>T;
	for(int i=1;i<=n;i++){
		string x,y;
		cin >>x>>y;
		mp[x]=y;
	}
	while(T--){
		string p,q;
		cin >>p>>q;
		int ans=0;
		for(int i=0;i<p.size();i++){
			for(int j=i;j<p.size();j++){
				string x=p.substr(i,j-i+1);
				if(mp[x]!=""){
					string v=p.substr(0,i)+mp[x]+p.substr(j+1,p.size()-j);
					if(v==q){
						ans++;
					}
				}
			}
		}cout <<ans<<'\n';
	}
	return 0;
}
