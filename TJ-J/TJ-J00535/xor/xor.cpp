#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n){
		cin>>a[i];
	}
	if(n==1 || (n==2 && a[1]!=a[2])) cout<<"0";
	if(n==2 && a[1]==a[2]) cout<<"1";
	return 0;}
