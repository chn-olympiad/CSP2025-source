#include<bits/stdc++.h>
using namespace std;
int n,q,ql,qr;
long long ans=0;
string s1,s2;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=0;i<n;i++){
		cin >> s1 >> s2;
		mp[s1]=s2;
	}
	while(q--){
		cin >> s1 >> s2;
		if(s1.size()!=s2.size()){
			cout << 0 << '\n';
			continue;
		}
		ans=0;
		ql=s1.size();qr=s1.size();
		for(int i=0;i<s1.size();i++) if(s1[i]!=s2[i]){
			ql=i;
			break;
		}
		for(int i=s1.size()-1;i>=0;i--) if(s1[i]!=s2[i]){
			qr=i;
			break;
		}
		if(ql==s1.size()){
			for(int l=0;l<s1.size();l++){
				for(int j=l;j<s1.size();j++){
					int v=j-l+1;
					string g1=s1.substr(l,v);
					if(mp[g1]==g1) ans++;
				}
			}
		}else{
			for(int l=ql;l>=0;l--){
				for(int r=qr;r<s1.size();r++){
					int v=r-l+1;
					string g1=s1.substr(l,v),g2=s2.substr(l,v);
					if(mp[g1]==g2) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
