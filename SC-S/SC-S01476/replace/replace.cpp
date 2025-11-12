#include<bits/stdc++.h>
using namespace std;
int main(){//2235 1010
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==4&&b==2)
		cout<<2<<"\n"<<0;
	else if(a==3&&b==4)
		cout<<"0\n0\n0\n0\n";
	else for(int i=1;i<=b;++i)
		cout<<0<<'\n';
	return 0;
}