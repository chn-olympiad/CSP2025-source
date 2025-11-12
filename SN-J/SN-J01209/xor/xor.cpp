#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500010];
void A(){
	for (int i=1;i<=n;i++){
		if (a[i]!=1){
			return ;
		}
	}
	cout<<n/2;
	exit(0);
}
void B(){
	int cntz=0,cnto=0;
	for (int i=1;i<=n;i++){
		if (a[i]>1){
			return;
		}
		if (a[i]==1) cnto++;
		if (a[i]==0) cntz++;
	}
	if (k==1){
		cout<<cnto<<endl;
		exit(0);
	}
	if (k==0){
		cout<<cntz+cnto/2<<endl;
		exit(0);
	}	
	return;
}
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	A();B();
	return 0;
}

