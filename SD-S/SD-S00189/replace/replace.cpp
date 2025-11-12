#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5;
string s1[N],s2[N],t1,t2;
ll l,r,n,q,ans;
bool ti(string s,string f,ll qi,string ans){
	//cout<<s<<" ti:"<<f<<" ans:"<<ans<<endl;
	for(ll i=0;i<s.size();i++){
		if(i>=qi&&i<=(qi+f.size()-1)){
			if(f[i-qi]!=ans[i]){
				//cout<<i-qi<<"+++++++++++:"<<f[i-qi]<<ans[i]<<endl;
				return 0;
			}
		}
		else{
			if(s[i]!=ans[i]) return 0;
		}
	}
	return 1;
}
bool tong(string z1,string z2,ll qi){
	for(ll i=qi;i<=qi+z2.size()-1;i++){
		if(z1[i]!=z2[i-qi]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(ll i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(ll j=1;j<=n;j++){
			if(t1.size()<s1[j].size()||t1.find(s1[j])>=t1.size()) continue;
			string s=t1;
			for(ll k=0;k<=s.size()-s1[j].size();k++){
				if(!tong(s,s1[j],k)) continue;
				//cout<<s1[j]<<" qi:"<<k<<endl;
				if(ti(s,s2[j],k,t2)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
