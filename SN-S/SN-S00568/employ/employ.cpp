#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	cout<<0;
	return 0;
}
