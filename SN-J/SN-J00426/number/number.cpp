#include<bits/stdc++.h> 
using namespace std;
int a[10],b[10],n[10];
int main(){
	int s,r=0;
	cin>>s;
	a[1]=s%10;
	a[2]=s/10%10;
	a[3]=s/100%10;
	a[4]=s/1000%10;
	a[5]=s/10000%10;
	a[6]=s/100000%10;
	a[7]=s/10000000%10;
	a[8]=s/100000000%10;
	a[9]=s/1000000000%10;
	for(int i=1;i<=9;i++){
		if(a[i]<=9&&a[i]>=1){ b[i]+=a[i];}
		else{  continue;}
	}
	for(int i=1;i<=9;i++){
		cout<<b[i];
	}
}
