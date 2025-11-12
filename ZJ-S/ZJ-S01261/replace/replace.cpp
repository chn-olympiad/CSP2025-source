#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;++i){
		int ans=0;
		cin>>t[0]>>t[1];
		int l=t[0].size();
		string tmp="";
		for(int i=0;i<l;++i){
			for(int j=1;j<=n;++j)for(int k=0;k<2;++k){
				if(i+s[j][k].size()<=l){
					string sub="";
					for(int qwq=i;qwq<i+s[j][k].size();++qwq)sub+=t[0][qwq];
					if(sub==s[j][k]){
						for(int qwq=0;qwq<i;++qwq)tmp+=t[0][qwq];
						tmp+=s[j][!k];
						for(int qwq=i+s[j][k].size();qwq<l;++qwq)tmp+=t[0][qwq];
						if(tmp==t[1])ans++;
					}
				}tmp="";
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
