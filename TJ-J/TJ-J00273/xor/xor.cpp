#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10],k,n,z=1;
	cin>>n>>k;
	if(k!=0){
			z--;
		}
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		if(a[i]+a[i+1]==k||a[i]-a[i+1]==k){
			z++;
		}
	} 
	cout<<z;
	return 0;
} 
