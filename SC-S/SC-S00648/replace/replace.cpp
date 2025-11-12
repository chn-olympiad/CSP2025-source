#include <bits/stdc++.h>
using namespace std;
int n,q;
int ans;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
	}
	for(int j=1;j<=q;++j){
		cin>>t1[j]>>t2[j];
		ans=0;
		for(int i=1;i<=n;++i){
			if(s1[i].size()>t1[j].size()) continue;
			for(int l=0;l<=t1[j].size()-s1[i].size();++l){
				string tmp=t1[j].substr(l,s1[i].size());
				if(tmp==s1[i]){
					string x=t1[j].substr(0,l-0);
					string z=t1[j].substr(l+s1[i].size(),t1[j].size()-l-s1[i].size()+1);
					string tmp1=x+s2[i]+z;
					if(tmp1==t2[j]) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
