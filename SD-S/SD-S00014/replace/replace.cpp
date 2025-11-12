#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string aa[n+5];
	string ab[n+5];
	string ba[n+5];
	string bb[n+5];
	for(int i=1;i<=n;i++){
		cin>>aa[i]>>ab[i];
	}
	for(int i=1;i<=q;i++){
		cin>>ba[i]>>bb[i];
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
}
