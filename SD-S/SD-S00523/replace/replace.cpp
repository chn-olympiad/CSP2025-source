#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e6+10;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.in","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int cur=0;
			int pos=0;
			while(pos!=-1){
				pos=t1.find(s1[i],pos);
				if(pos==-1){
					break;
				}
				string tmp=t1.substr(0,pos)+s2[i]+t1.substr(pos+s1[i].size(),t1.size()-pos-s1[i].size()+1);
				if(tmp.size()!=t2.size()){
					pos+=s1[i].size();
					continue;
				}
				bool fl=1;
				for(int j=0;j<tmp.size();j++){
					if(tmp[j]!=t2[j]){
						fl=0;
						break;
					}
				}
				if(fl){
					ans++;
					break;
				}
				pos+=s1[i].size();
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
