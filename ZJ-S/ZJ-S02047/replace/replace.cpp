#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[2000005],s2[2000005],q1[2000005],q2[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;++i)
		cin>>q1[i]>>q2[i];
	if(n*q<=1e8){
		for(int i=1;i<=q;i++){
			if(q1[i].size()!=q2[i].size()){
				cout<<"0\n";
				continue;
			}
			int ans=0;
			string s=q1[i];
			for(int j=1;j<=n;++j){				
				if(s.find(s1[j])!=string::npos){
					int k=s.find(s1[j]);
					string str=s.substr(0,k)+s2[j]+s.substr(k+s2[j].size());
					if(str==q2[i]) ++ans;
				}
			}
			cout<<ans<<'\n';
		}
	}else{
		int ans=0;
		for(int i=1;i<=q;i++){
			if(q1[i].size()!=q2[i].size()){
				cout<<"0\n";
				continue;
			}
			int k1=q1[i].find("b");
			int k2=q2[i].find("b");
			if(k1>k2) swap(k1,k2);
			string ss1=q1[i].substr(k1,k2-k1+1);
			string ss2=q2[i].substr(k1,k2-k1+1);
			for(int j=1;j<=n;++j) if(s1[j].find(ss1)!=string::npos && s2[j].find(
			ss2)!=string::npos) ++ans;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
