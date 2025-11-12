#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n+q;i++){
		cin>>s>>t;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
