#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10,M=1e6+10;
string a[N],b[N];
unordered_map<string,string>mp;
signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q,mx=0;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mp[a[i]]=b[i];mx=max(mx,a[i].size());
	}
	int res=0;
	for(int i=1;i<=q;i++){
		string s,t;cin>>s>>t;res=0;
		for(int i=1;i<=mx;i++){ 
			for(int j=0;j<s.size();j++){
				if(mp.count(s.substr(j,i))){
				string p=s.substr(0,j)+mp[s.substr(j,i)];
				bool ff=1;
				for(int k=i+j;k<s.size();k++)if(s[k]!=t[k]){ff=0;break;}
				if(p==t.substr(0,j+i)&&ff)res++,cout<<s.substr(j,i)<<endl;
				
			}}
		}cout<<res<<endl;
	}
	return 0;
}
