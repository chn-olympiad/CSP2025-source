#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
bool bj(string a,string b,int l,int r){
	if(r>=b.length())return 0;
	for(int i=l;i<=r;++i){
		if(a[i-l]!=b[i])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int it=0;it<t1.length();++it){
				if(bj(s1[i],t1,it,it+s1[i].length()-1)){
					string tmp="";
					for(int j=0;j<it;++j) tmp+=t1[j];
					tmp+=s2[i];
					for(int j=it+s1[i].length();j<t1.length();++j) tmp+=t1[j];
					if(tmp==t2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
fc replace3.ans replace.out
4 3
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
xabcx xadex
*/
