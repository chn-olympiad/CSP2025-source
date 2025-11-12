#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int s;
	cin>>s;
	int num=0;
	for(int i;i<=num;i++){
		num++;
		cout<<num;
	}
	if(s==num){
		cout<<s;
	}
	if(s<num){
		cout<<num;
	}
	cout<<s;
	return 0;
}
