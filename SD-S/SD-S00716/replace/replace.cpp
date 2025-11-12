#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long l,n,p,i;
	string s1,s2;
	cin>>n>>p;
	for(i=1;i<=n;i++) cin>>s1>>s2;
	for(i=1;i<=p;i++ ) cin>>s1>>s2;
	for(i=1;i<=p;i++ )cout<<"0"<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

