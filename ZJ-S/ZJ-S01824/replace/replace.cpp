#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,pw[5000008]={1},L1,L2,ans;
string s[214514][2],t1,t2;



int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(ll i=1;i<=5000000;i++)pw[i]=pw[i-1]*103;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0;
			continue;
		}
		for(ll i=1;i<=n;i++){
			ll idx=0;
//			cout<<string::npos;
			while((idx=t1.find(s[i][0],idx))!=string::npos){
//				cout<<idx<<'\n';
				if((t1.substr(0,idx-1)==t2.substr(0,idx-1))||((t1.substr(0,idx-1).empty()&&t2.substr(0,idx-1).empty()))&&(t1.substr(idx+s[i][0].size())==t2.substr(idx+s[i][0].size())||(t1.substr(idx+s[i][0].size()).empty()&&t2.substr(idx+s[i][0].size()).empty())&&(s[i][1]==t2.substr(idx,s[i][0].size()))))
				ans++;
//				cout<<(t1.substr(0,idx-1)==t2.substr(0,idx-1))||((t1.substr(0,idx-1).empty()&&t2.substr(0,idx-1).empty()))<<'\n';
//				cout<<t1.substr(idx+s[i][0].size())<<' '<<t2.substr(idx+s[i][0].size())<<'\n';
//				cout<<s[i][1]<<' '<<t2.substr(idx,s[i][0].size())<<'\n';
//				cout<<ans<<'\n';
				idx++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}