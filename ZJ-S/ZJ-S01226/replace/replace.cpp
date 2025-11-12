#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,unordered_map<string,int>> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1][s2]++;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int len=t1.size();
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int sz=1;sz<=len;sz++){
			for(int l=0;l+sz-1<len;l++){
				string s1=t1.substr(0,l);
				string s2=t2.substr(0,l);
				string ss1=t1.substr(l+sz,len-l-sz);
				string ss2=t2.substr(l+sz,len-l-sz);
				if(s1==s2&&ss1==ss2){	
					string str1=t1.substr(l,sz);
					string str2=t2.substr(l,sz);
					ans+=mp[str1][str2];
				}
			}
		}
		cout<<ans<<"\n";
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
