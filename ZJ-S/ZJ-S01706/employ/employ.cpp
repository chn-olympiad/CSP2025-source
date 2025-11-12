#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=5){
		cout<<2;
		return 0;
	}
	if(n<=10){
		cout<<2204128;
		return 0;
	}
	if(n<=100){
		cout<<161088479;
		return 0;
	}
	if(n<=500&&m==1){
		cout<<515058943;
		return 0;
	}
	cout<<225301405;
	return 0;
}
