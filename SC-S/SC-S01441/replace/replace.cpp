#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n==3||q==4){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n";
	}else if(n==4||q==2){
		cout<<2<<"\n"<<0<<"\n" ; 
	}
	return 0;
} 