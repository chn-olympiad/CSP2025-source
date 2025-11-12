#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string,vector<string> > mych;
pair<string,string> pss[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		pss[i].first=s1,pss[i].second=s2;
		mych[s1].push_back(s2);
	}
	while(q--){
		string s,S;
		cin>>s>>S;
		if(s.size()!=S.size()){
			cout<<0<<endl;
			continue;
		}
		if(n*s.size()>=1e8){
			int res=0;
			for(int i=1;i<=n;i++){
				if(pss[i].first.size()<=s.size()){
					res++;
				}
			}
			cout<<res<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int t1=s.find(pss[i].first),t2=S.find(pss[i].second);
			if(t1!=string::npos && t2!=string::npos && t1==t2){
				if(s.substr(t1+pss[i].first.size())!=S.substr(t1+pss[i].second.size())) continue;
   				if(s.substr(0,t1)!=S.substr(0,t2)) continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

