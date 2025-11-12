#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main(){
	fropen("number.in","r",ctdin);
	fropen("number.out","w",ctdout);
	string s;
	cin>>s;
	string a,b;
	for(int i=0;i<=s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){
			a[i]=s[i];
			
		}
	}
	
	for(int i=0;i<=s.size();i++){
		for(int j=1;j<=s.size();j++){
			if(a[i]>a[j]){
				a[i]=b[i];
			}
			else if(a[i]<a[j]){
				a[j]=b[i];
			}
			
		}
	}
	for(int i=0;i<b.size();i++){
		cout<<b[i];
	}
	return 0;
} 
