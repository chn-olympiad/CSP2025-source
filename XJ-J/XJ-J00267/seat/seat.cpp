#include<bits/stdc++.h> 
using namespace std;
int main(){

	int n,m;
	int b;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];}
	int q=a[0];	
	for(int j=0;j<n*m;j++){
		for(int g=j+1;g<n*m;g++){
			if(a[j]>a[g]){
				a[g]=q;
				a[g]=a[j];
				a[j]=q;
			}
			
		}
	}
	for(int i=0;i<n*m;i++){
		cout<<a[i];}
	return 0;
	
}
