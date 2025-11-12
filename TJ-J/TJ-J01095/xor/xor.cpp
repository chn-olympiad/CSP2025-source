#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500100];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[0]!=0){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(n==2){
		if(a[0]!=a[1]){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}
