#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+10,mod=998244353;
int n,q;
string s[N][2],t[2];
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],mp[s[i][0]]=s[i][1];
	while(q--){
		cin>>t[0]>>t[1];
		int len1=t[0].size(),len2=t[1].size();
		if(len1!=len2){cout<<0<<'\n';continue;}
		int cnt=0,en=-1;
		for(int i=len1-1;i>=0;i--) if(t[0][i]!=t[1][i]){en=i;break;}
		for(int i=0;i<len1;i++){
			for(int j=max(i,en);j<len1;j++){
				if(mp[t[0].substr(i,j-i+1)]==t[1].substr(i,j-i+1)) cnt++;
			}
			if(t[0][i]!=t[1][i]) break;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}