#include <iostream>
using namespace std;
int paixu(int x[],int n,int m,int c,int r){
	int s=n*m;
	for(int i=1;i<n*m;i++){
		if(x[0]<x[i]){
			s--;
		}
	}
	cout<<s<<" ";
	c=s/m+1;
	r=s%m;
	cout<<c<<" "<<r;
}
int main(){
	int n,m,c,r;
	c=0;
	r=0;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	paixu(a,n,m,c,r);
}
