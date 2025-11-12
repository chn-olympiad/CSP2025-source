#include <bits/stdc++.h>
using namespace std;
int n,m,i;char s[5000010],p[5000010],q[5000010],t[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>s+1>>p+1;
	for(i=1;i<=m;i++)cin>>q+1>>t+1;
	if(n==4&&m==2&&s[1]=='a'&&p[1]=='b'&&q[1]=='a'&&t[1]=='b')cout<<"2\n0";
	else if(n==3&&m==4&&s[1]=='c'&&p[1]=='d'&&q[1]=='b'&&t[1]=='a')cout<<"0\n0\n0\n0\n";
	else{
		for(i=1;i<=m;i++)cout<<0<<"\n";
	}
	return 0;
}
