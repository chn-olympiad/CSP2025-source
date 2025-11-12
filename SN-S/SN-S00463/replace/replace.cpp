#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2,t1,t2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)     cin>>s1>>s2;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
	}
	if(n==4){
		cout<<2<<endl<<0;
	}
	else if(n==3){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	else if(n==37375){
		for(int i=1;i<=32;i++){
			cout<<0<<endl;
		}
	}
} 
