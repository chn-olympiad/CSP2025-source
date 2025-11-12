#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans;
string ss[1111],tt[1111],s,t;
map<string,string>mp;
bool stt(string a,string b){
	if(a.size()!=b.size())return 0;
	for(int i=0;i<a.size();i++)if(a[i]!=b[i])return 0;
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>ss[i]>>tt[i];
	while(q--){
		cin>>s>>t;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int i1=0;i1<s.size()-ss[i].size();i1++){
				int f=0;
				for(int j=0;j<ss[i].size();j++){
					if(ss[i][j]==s[i1+j])f=i;
				}
				string st="";
				for(int i11=0;i11<f;i11++)st+=s[i11];
				st+=tt[i];
				for(int i11=f+ss[i].size();i11<s.size();i11++)st+=s[i11];
				if(stt(st,s))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
