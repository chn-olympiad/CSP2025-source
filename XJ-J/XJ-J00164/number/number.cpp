#include<bists/stdc++.h>
using namespace std;
int main(){
	int s[9],a[9],t;
	for(int i=0;i<9;i++){
		cin>>s[i];
		if(s[i]+0==s[i]){
			a[i]=s[i];
		}else{
			container; 
		}
	}
	for(int i=9;i>0;i--){
		if(a[i]>a[i-1]){
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}else{
			container;
		}
	}
	for(int i=0;i<9;i++){
		cout<<a[i];
	}
	return 0;
} 
