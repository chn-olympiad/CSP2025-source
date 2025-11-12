#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ull=unsigned long long;
unordered_map<ull,unordered_map<ull,int>>g;
int msz;
ull calc(string s,int l,int r){
	ull res=0;
	for(int i=l;i<=r;i++){
		res=res*1331+s[i]-'a';
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		msz=max(msz,(int)s1.size());
		ull res1=calc(s1,0,s1.size()-1),res2=calc(s2,0,s2.size()-1);
		g[res1][res2]=1;
	}
	while(q--){
		string s1,s2;cin>>s1>>s2;
		if(s1.size()!=s2.size()||(int)s1.size()>msz){
			cout<<0<<endl;
			continue;
		}
		int l=-1,r=0;
		for(int i=0;i<(int)s1.size();i++){
			if(s1[i]!=s2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		int ans=0;
		for(int i=1;i<=l;i++){
			for(int j=r;j<(int)s1.size();j++){
				int x=calc(s1,i,j),y=calc(s2,i,j);
				if(g.count(x)&&g[x].count(y)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
