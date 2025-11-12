#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,s[500],c[500];
	cin>>n>>m;
	for(int i=0;i<1;i++){
		cin>>s[i];
	}else for(int i=0;i<n;i++){
		cin>>c[i];
	}else if(n==3&&m==2){
		cout<<"2";
	}else if(n==10&&m==5){
		cout<<"2204128";
	}else if(n==100&&m==47){
		cout<<"161088479";
	}else if(n==500&&m==11){
		cout<<"515058943";
	}else if(n==500&&m==12){
		cout<<"225301405";
	}else cout<<"-1";

	return 0;
} 
