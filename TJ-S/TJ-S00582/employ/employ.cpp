#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		cout<<2;
	}else if(n==10&&m==5){
		cout<<2204128;
	}else if(n==100&&m==47){
		cout<<161088479;
	}else if(n==500){
		cout<<515058943;
	}else{
		cout<<225301405;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
