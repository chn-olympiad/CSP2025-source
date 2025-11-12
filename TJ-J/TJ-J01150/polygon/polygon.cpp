#include <bits/stdc++.h>
using namespace std;
const int MAX=0x7fffffff;
int jc(int n){
	int i=n;
	while(true){
		i--;
		if(i==0)break;
		n=n*i;
	}
	return n;
}
int C(int n,int m){
	int a,b,c;
	c=m-n;
	a=jc(m)/jc(c);
	b=jc(n);
	return a/b;
}
int n; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				
			}
		}
	}
	return 0;
}

