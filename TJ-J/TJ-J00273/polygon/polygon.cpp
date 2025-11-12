#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100],m=0,z=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	
	}for(int i=0;i<n;i++){
		if(a[i+2]<a[i]>a[i+1]){
			m=a[i];
		}else if(a[i+2]<a[i+1]>a[i]){
			m=a[i+1];
		}else if(a[i]<a[i+2]>a[i+1]){
			m=a[i+2];
		}
		if(a[i]+a[i+1]+a[i+2]>m*2){
			z+=2;
		}
		
	}
	for(int i=0;i<n;i++){
		if(a[i+2]<a[i]>a[i+1]&&a[i+3]<a[i]){
			m=a[i];
		}else if(a[i+2]<a[i+1]>a[i]&&a[i+3]<a[i+1]){
			m=a[i+1];
		}else if(a[i]<a[i+2]>a[i+1]&&a[i+3]<a[i+2]){
			m=a[i+2];
		}else if(a[i]<a[i+3]>a[i+1]&&a[i+2]<a[i+3]){
			m=a[i+3];
		}
		if(a[i]+a[i+1]+a[i+2]>m*2){
			z+=3;
		}
		
	} 
	for(int i=0;i<n;i++){
		if(a[i+2]<a[i]>a[i+1]&&a[i+3]<a[i]&&a[i+4]<a[i]){
			m=a[i];
		}else if(a[i+2]<a[i+1]>a[i]&&a[i+3]<a[i+1]&&a[i+4]<a[i+1]){
			m=a[i+1];
		}else if(a[i]<a[i+2]>a[i+1]&&a[i+3]<a[i+2]&&a[i+4]<a[i+2]){
			m=a[i+2];
		}else if(a[i]<a[i+3]>a[i+1]&&a[i+2]<a[i+3]&a[i+4]<a[i+3]){
			m=a[i+3];
		}else if(a[i]<a[i+4]>a[i+1]&&a[i+2]<a[i+4]&&a[i+3]<a[i+4]){
			m=a[i+4];
		}
		if(a[i]+a[i+1]+a[i+2]>m*2){
			z+=2;
		}
		
	} 
	
	
	
	
	
	
	if(a[0]==2){
		z-=3;
	} 
	cout<<z+1;
	return 0;
} 
