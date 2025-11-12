#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,string> mp;
unordered_map<string,bool> mp1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int p,q,maxx=0;string s1,s2,s;
	cin>>p>>q;
	for(int i=1;i<=p;i++) cin>>s1>>s2,mp[s1]=s2,mp1[s1]=1,maxx=max(maxx,int(s1.size()));
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){cout<<0<<"\n";continue;}
		int n=s1.size(),pre=0,lst=n-1;
		while(s1[pre]==s2[pre]) pre++;
		while(s1[lst]==s2[lst]) lst--;
		if(lst-pre+1>maxx){cout<<0<<"\n";continue;}
		int ans=0;
		for(int i=pre;i>=0;i--){
			for(int j=lst;j<n;j++){
				if(j-i+1>maxx) continue;
				s=s1.substr(i,j-i+1);
				if(mp1[s]&&mp[s]==s2.substr(i,j-i+1)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

