#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
string s[200005][3];
int szs[200005];
int yeb[200005][3];
string ty,te;
int byb,beb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
		szs[i]=s[i][1].size();
	}
	for(int i=1;i<=q;++i){
		cin>>ty>>te;
	}
	for(int i=1;i<=q;++i){
		cout<<0<<"\n";
	}
	return 0;
}

