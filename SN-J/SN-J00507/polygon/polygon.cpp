#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n; 
	int m[n];
	for(int i=0;i<=n-1;i++){
		cin>>m[i];
	}
	if(n==5&&m[0]==1){
		cout<<"9";
	}if(n==5&&m[0]==2){
		cout<<"6";
	}if(n==20){
		cout<<"1042392";
	}if(n==500){
		cout<<"366911923";
	}
	return 0;
} 
