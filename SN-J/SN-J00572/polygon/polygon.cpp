#include<bits/stdc++.h>
using namespace std; 
int main(){
	int n,k[n],a;
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> k[i];
	}
	for(int i=0;i<n;i++){
		if(k[i]+k[i+1]>k[i+2]||k[i]+k[i+1]+k[i+2]>k[i+3]||k[i]+k[i+1]+k[i+2]+k[i+3]>k[i+4]||k[i]+k[i+1]+k[i+2]+k[i+3]+k[i+4]>k[i+5]){
			 a+=1;		
		}	
	}
	cout << a+1;
}
