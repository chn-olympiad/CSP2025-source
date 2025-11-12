//SN-J01002   贺宇轩  西安市经开第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s[],v,w;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int j=2;j<=n;j++){
		if(s[j]>s[j-1]){
			v=s[j];
	}
		else{
			v=s[j-1];
		}
	}
	v*=2;
	if(s[1]+s[2]>v){
		w++;	
	}
	if(s[1]+s[3]>v){
		w++;	
	}
	if(s[2]+s[3]>v){
		w++;	
	}
	cout<<w;
}
