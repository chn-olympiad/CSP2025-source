#include<bits/stdc++.h>
using namespace std;
int n,q,a,b,len,ans;
string s[2],t[2];
map<string,string>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0]>>s[1];
		mp[s[0]]=s[1];
	}
	for(int i=1;i<=q;i++){
		a=b=0;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		else{
			len=t[0].size();
			while(t[0][a]==t[1][a]) a++;
			while(t[0][len-b-1]==t[1][len-b-1]) b++;
//			cout<<a<<" "<<b<<"\n";
			for(int i=0;i<=a;i++)
				for(int j=0;j<=b;j++){
//					cout<<(mp[t[0].substr(i,len-i-j)]==t[1].substr(i,len-i-j))<<"\n";
					if(mp[t[0].substr(i,len-i-j)]==t[1].substr(i,len-i-j)) {
//						cout<<"\n\n\n"<<i<<" "<<j<<"\n\n\n\n";
						ans++;
					}
				}
			cout<<ans<<"\n";
			ans=0;
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb





3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/