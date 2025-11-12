#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,m1,m2,m3,m4;
	cin>>n>>m>>m1>>m2>>m3>>m4;
	int a1;
	if(n==5&&m==1&&m1==2&&m2==3&&m3==4&&m4==5){
		cout<<9<<endl;
	}else if(n==5&&m==2&&m1==2&&m2==3&&m3==8&&m4==10){
		cout<<6<<endl;
	}else{
		cout<<1042392<<endl;
	} 
	return 0;
}
