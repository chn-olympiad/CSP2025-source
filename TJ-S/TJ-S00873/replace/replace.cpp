#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,vector<string>>a;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s,ss;
		cin>>s>>ss;
		a[s].push_back(ss);
		a[ss].push_back(s);
	}
	while(m--){
		string s,ss;
		cin>>s>>ss;
		if(s.size()!=ss.size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=ss[i]){
				l=i;
				break;
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]!=ss[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(i>l){
				continue;
			}
			for(int j=i;j<s.size();j++){
				if(j<r){
					continue;
				}
				string sss=s.substr(i,j-i+1);
				string ssss=ss.substr(i,j-i+1);
				for(auto v:a[sss]){
					if(v==ssss){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
