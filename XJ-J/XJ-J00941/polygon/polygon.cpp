#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,s=0;
	float a[1000];
	cin>>n;
	for(int i=0;i<n,i++;){
		cin>>a[i];
	}
	for(int i=0;i<n-3,i++;){
		if(((a[i]+a[i+2])*3)/4>max(a[i],a[i+1],a[i+2])){
			s++;
		}		
	}
	if(n>=4){
		for(int i=0;i<n-4,i++;){
			if(((a[i]+a[i+3])*4)/4>max(a[i],a[i+1],a[i+2],a[i+3])){
				s++;
			}		
		}
	}
	if(n>=5){
		for(int i=0;i<n-5,i++;){
			if(((a[i]+a[i+4])*5)/2>max(a[i],a[i+1],a[i+2],a[i+3],a[i+4])){
				s++;
			}		
		}
	}
	if(n>=6){
		for(int i=0;i<n-5,i++;){
			if(((a[i]+a[i+5])*6)/2>max(a[i],a[i+1],a[i+2],a[i+3],a[i+4],a[i+5])){
				s++;
			}		
		}
	}
	if(n>=7){
		for(int i=0;i<n-5,i++;){
			if(((a[i]+a[i+6])*7)/2>max(a[i],a[i+1],a[i+2],a[i+3],a[i+4],a[i+5],a[i+6])){
				s++;
			}		
		}
	}
	return 0;
}
