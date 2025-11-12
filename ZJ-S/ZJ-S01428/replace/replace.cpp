//10
#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,vector<string> > mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1].push_back(s2);
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		for(int len=1;len<=l1;++len){
			for(int l=0;l+len-1<l1;++l){
				string s=t1.substr(l,len),s1=t1;
				if(mp[s].size()==0) continue;
				for(int i=0;i<mp[s].size();++i){
					string tt=mp[s][i];
					s1.erase(l,len);
					s1.insert(l,tt);
					//cout<<s1<<' '<<t2<<endl;
					if(s1==t2) ans++;
					s1=t1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
