#include<bits/stdc++.h>
using namespace std;
char array[1000001];
int arr[1000001];
int main(){
	string s;
	int a=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			array[a++]=s[i];
		}
	}
	for(int i=0;i<a;i++){
		arr[i]=int(array[i])-48;
	}
	for(int i=0;i<a;i++){
		if(arr[i]==9){
			cout<<9;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==8){
			cout<<8;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==7){
			cout<<7;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==6){
			cout<<6;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==5){
			cout<<5;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==4){
			cout<<4;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==3){
			cout<<3;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==2){
			cout<<2;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==1){
			cout<<1;
		}
	}for(int i=0;i<a;i++){
		if(arr[i]==0){
			cout<<0;
		}
	}
	return 0;
}
