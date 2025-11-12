#include<bits/stdc++.h>
#define ri register int
using namespace std;
string s,s1,t,t1;
map<int,set<pair<int,int>>>mp;
int p,p1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q;cin>>n>>q;
	for(ri i=0,x;i<n;i++){
		cin>>s>>s1;x=s.size();
		for(ri j=0;j<x;j++){
			if(s[j]=='b')p=j;
			if(s1[j]=='b')p1=j;
		}mp[p-p1].insert({p,x});
	}for(ri i=0,x;i<q;i++){
		cin>>t>>t1;x=t.size();
		if(x!=t1.size()){
			cout<<0<<'\n';continue;
		}for(ri j=0;j<x;j++){
			if(t[j]=='b')p=j;
			if(t1[j]=='b')p1=j;
		}auto z=mp[p-p1];
		auto it=z.begin();
		int cnt=0;
		while(it!=z.end()&&(*it).first<=p){
			it++;if(x>=(*it).second)cnt++;
		}cout<<cnt<<'\n';
	}
	return 0;
}
