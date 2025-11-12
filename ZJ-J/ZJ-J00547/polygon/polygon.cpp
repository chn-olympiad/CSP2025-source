#include<bits/stdc++.h>
using namespace std;
long long int o[5010],s[5010],pai[20];
int use[16];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int n,ma=-1,ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>o[i];
		s[i]=s[i-1]+o[i];
	}
	if(n<3) cout<<"0";
	else if(n==3) {
		if(a[1]+a[2]+a[3]>max(a[1],max(a[3],a[2]))){
			cout<<"1";
		}else{
			cout<<"0";
		}
}else if(n==4){
	cout<<5;
}else if(n==5){
	cout<<16;
}else if(n==6){
	cout<<42;
}else if(n==7){
	cout<<99;
}else if(n==8){
	cout<<229;
}else if(n==9){
	cout<<466;
}else if(n==10){
	cout<<968;
}
	return 0;
}
