#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,n;
	cin>>s>>n;
	for(int i=0;i<=s;i++){
		for(int j=0;j<=i;j++){
			if(i*j==s){
				cout<<i*j;
			}
		}
	}
	
	
	
	
	
	return 0;
}