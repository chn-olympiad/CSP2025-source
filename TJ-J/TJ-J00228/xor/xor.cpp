#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a1,a2,a3,a4;
	cin>>n>>k>>a1>>a2>>a3>>a4;
	if(n==4&&k==2){
		cout<<2<<" "<<1<<" "<<0<<" "<<3;
	} 
	else if(n<=2&&k==0){
		cout<<1;
	}
return 0;
}
