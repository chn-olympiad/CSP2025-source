#include<bits/stdc++.h>
using namespace std;
int n,a[5001]={},x,y,z=0;
void solo(){
	int b[5001]={};
	x++;
	y=0;
	for(int i=0;i<x;i++){
		y+=b[i];
	}
	if(y>b[x]){
		z++;
		return;
	}
	for(int i=0;i<n;i++){
		b[x]=a[i];
		sort(b,b+x);
		solo();
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	x=0;
	solo();
	cout<<z;
}
