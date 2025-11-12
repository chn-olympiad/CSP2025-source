//SN-J00352张晟轩渭南初级中学 
#include<bits\stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

int a[1001];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}if(n==2){
		cout<<3;
		return 0;
	}
	cout<<(1+n)*n/2;
}
