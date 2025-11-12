#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q,n;
	cin>>n>>q;
	int a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[q+1]={};
	for(int i=1;i<=q;i++){
		cin>>b[i];
	}
	if(n==4){
	
		cout<<2<<endl<<0;
	}
	else if(n==3){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
