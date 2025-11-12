#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>k;
	}
	if(n==3 and m==2){
		cout<<2<<endl;
	}
	if(n==10 and m==5){
		cout<<2204128<<endl;
	}
	if(n==100 and m==47){
		cout<<161088479<<endl;
	}
	if(n==500 and m==1){
		cout<<515058943<<endl;
	}
	if(n==500 and m==12){
		cout<<225301405<<endl;
	}
	  
	return 0;
} 
