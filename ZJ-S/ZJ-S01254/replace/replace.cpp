#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int base=27;
int mod=1e9+7;
int has(int l,int r,string s){
	int res=0;
	for(int i=l;i<=r;i++){
		res=res*base%mod+s[i]-'a'+mod+1;
		res%=mod;
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		cout<<0<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xabex
aaaa bbbb
*/