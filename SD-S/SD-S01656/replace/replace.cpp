#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		int ans=0,l=-1,r=0;
		int len=s1.size();
		if(len!=s2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<len;i++){
			if(l==-1&&s1[i]!=s2[i]) l=i;
			if(s1[i]!=s2[i]) r=i;
		}
		for(auto it=mp.begin();it!=mp.end();it++){
			int len=it->first.size();
			if(len<r-l+1) continue;
			int pos1=s1.find(it->first);
			int pos2=s2.find(it->second);
			if(~pos1==0||~pos2==0) continue;
			if(l>=pos1&&r<=pos1+len&&pos1==pos2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

