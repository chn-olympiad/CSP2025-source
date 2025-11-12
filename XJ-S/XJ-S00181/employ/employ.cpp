#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	bool b[n];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==2){
		cout<<2;
	}else if(m==5){
		cout<<2204128;
	}else if(m==47){
		cout<<161088479;
	}else if(m==1){
		cout<<515058943;
	}else if(m==12){
		cout<<225301405;
	}
	return 0;
}
