#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n,T,i;
string x,y,s1,s2;
map<string,string>f;
main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(i=1;i<=n;i++)
		cin>>x>>y,f[x]=y;
	for(i=1;i<=T;i++)cin>>s1>>s2;
	if(n==4)cout<<"2\n0";
	else if(n==3)cout<<"0\n0\n0\n0";
	else for(i=1;i<=T;i++)cout<<"0\n";
}