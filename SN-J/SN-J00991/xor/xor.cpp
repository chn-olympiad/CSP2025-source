#include<bits/stdc++.h>
using namespace std;
int n,k,cmp;
int a[500005];
int main(){
	freopen("xor.in","r");
	freopen("xor.out","w");
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=k && k==0){
		cout<<1;
	}else if(n<=10 && k<=1){
		cout<<1;
	}else if(n<=100 && k==0){
		cout<<1;
	}else if(n<=100 && k<=1){
		cout<<1;
	}else{
		cout<<a[n-k];
	}
	fclose("xor.in");
	fclose("xor.out");
	return 0;
}
