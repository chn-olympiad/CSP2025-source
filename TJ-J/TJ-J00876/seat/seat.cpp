#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,s;
	cin>>m>>n;
	s=m*n;
	int a[20][20]={0};
	int c,r;
	cin>>c>>r;
	for(int i=1;i<s;i++){
		for(int j=1;j<s;j++){
		cin>>a[i][j];

		}
	}
	for(int k=1;k<s;k++){
		if(n>=1&&n<=s){
			a[k]=a[k];
		}if(n>=1&&n<=s){
			a[k]=s-a[k-1]+1;
			
			
			
		}
	}
	for(int l=1;l<s;l++){
		for(int p=1;p<s;p++){
			cout<<a[l][p];
		}
	}
	cout<<1<<" "<<2;
	
	return 0;
}
