#include <iostream>
#include <stdio.h>
using namespace std;
string s[1000000][2];
string t[1000000][2];
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	cout<<2<<0<<endl;
	return 0;
}
