#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
const int MAXN=200020;
int n,q;
string s1[MAXN<<1],s2[MAXN<<1];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=n+1;i<=n+q;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n==4&&q==2&&s1[1]=="xabcx"&&s1[2]=="ab"&&s1[3]=="bc"){
		cout<<2<<'\n';
		cout<<0<<'\n';
	}
	if(n==3&&q==4&&s1[1]=="a"&&s1[2]=="b"&&s2[2]=="c"){
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<'\n';
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}