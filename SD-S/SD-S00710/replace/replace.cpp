#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
map<pair<string,string>,int> m;
int kong,n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1="",s2="";
		cin>>s1>>s2;
		m[{s1,s2}]++;
	} 
	for(int i=1;i<=q;i++){
		string s,ss;
		cin>>s>>ss;
		if(s.size()!=ss.size()){
			cout<<0<<"\n";continue;
		}
		int pre=0,hou=s.size()-1,ans=0,len=s.size();
		while(s[pre]==ss[pre]) pre++;
		while(s[hou]==ss[hou]) hou--;
		for(int j=0;j<=pre;j++){
			for(int k=0;k<=(len-hou-1);k++){
				string ss1="",ss2="";
				for(int ii=pre-j;ii<=hou+k;ii++){
					ss1.push_back(s[ii]);
					ss2.push_back(ss[ii]);
				}
				ans+=m[{ss1,ss2}];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
