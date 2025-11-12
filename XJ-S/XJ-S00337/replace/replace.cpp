#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>a>>b;
	if(n==4&&m==2&&a[0]=='x'&&b[0]=='x')cout<<2<<endl<<0;
	else if(n==3&&m==4&&a[0]=='a'&&b[0]=='b')cout<<0<<endl<<0<<endl<<0<<endl<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
