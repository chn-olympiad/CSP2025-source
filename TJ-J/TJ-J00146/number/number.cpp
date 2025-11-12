#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int a[1000000],b=0;
	string s;
	cin>>s;
	int i=0;
	r=s-48;
	if(s==1||s==2||s==3||s==4||s==5||s==6||s==7||s==8||s==9){
		a[i]=s;
	}
	if(a[i]>b){
		b=a[i];
	}
	cout << b;
	a[i]=a[i-1];
	return 0;
} 
