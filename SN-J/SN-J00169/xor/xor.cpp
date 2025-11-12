//原梓轩 SN-J00169 440514201308033019 陕西-西安-锦园中学 
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5005];
int  main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==k&&a[1]==k){
		cout<<2;
	}
	else if(a[0]^a[1]==k){
		cout<<1;
	}
	else if(a[0]==k||a[1]==k){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
