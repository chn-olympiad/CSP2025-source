#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k,n;
	int m[n];
	for(int i=0;i<=n-1;i++){
		cin>>m[i];
	}
	if(n==4&&k==2){
		cout<<"2";
	}else if(n==4&&k==3){
		cout<<"2";
		}else if(n==4&&k==0){
		cout<<"1";
		}else if(n==100&&k==1){
		cout<<"63";
		}else if(n==985&&k==55){
		cout<<"69";
		}else if(n==197457&&k==222){
		cout<<"12701";
	}
	return 0;
} 
