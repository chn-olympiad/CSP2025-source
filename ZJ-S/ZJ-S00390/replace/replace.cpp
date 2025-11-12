#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,L[200005],R[200005];
string s[200005],t[200005],u,v;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		int l=0,r=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]!=t[i][j]){
				l=j;
				break;
			}
		}
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]!=t[i][j])r=j;
		}
		L[i]=l,R[i]=r;
	}
	while(q--){
		cin>>u>>v;
		int cnt=0;
		int l=0,r=0;
		for(int j=0;j<u.size();j++){
			if(u[j]!=v[j]){
				l=j;
				break;
			}
		}
		for(int j=0;j<u.size();j++){
			if(u[j]!=v[j])r=j;
		}
		for(int i=1;i<=n;i++){
			if(s[i].substr(L[i],R[i]-L[i]+1)!=u.substr(l,r-l+1)||t[i].substr(L[i],R[i]-L[i]+1)!=v.substr(l,r-l+1))continue;
			if(l<L[i]||s[i].size()-R[i]>u.size()-r)continue;
			if(u.substr(l-L[i],s[i].size())==s[i]&&v.substr(l-L[i],s[i].size())==t[i])cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
