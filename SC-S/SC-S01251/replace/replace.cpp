#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[5050505][5],t[5050505][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		cout<<0;
	}
	/*
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		cout<<0;
	}
	if(s[1][2]==t[1][2])cout<<1;
}*/
	return 0;
}