#include<bits/stdc++.h>
using namespace std;
 int main(){
 	string a; 
 	cin>>a;
 	string ans;
 	string b;
 	for(int i=0;i<a.size();i++){
 		if('0'<=a[i]&&a[i]<='9'){
 			b+=a[i];
		 }
	 }
	while(true){
		if(b.size()==1){
			cout<<b;
			return 0;		
			}
		else{
		for(int i=0;i<b.size();i++){
 			if(b[i]<b[i+1]){
 				ans[i]=b[i+1];
 				
		 		}
			}
			cout<<ans;
		}
		return 0;
	}
	
	frenopen("number.in","r",std in);
 	frenopen("number.out","w",std out);
 	return 0;}
