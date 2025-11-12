#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m;
	int c,r;
	cin>>n>>m;
	int a=n*m;
	int num[a+1];
	for(int i=0;i<a;i++){
		cin>>num[i];
	}
	int R=num[0];
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			if(num[j]>num[i]){
				int b=num[i];
				num[i]=num[j];
				num[j]=b;
			}
		}
	}
	int d;
	for(int i=0;i<a;i++){
		if(num[i]==R){
			d=i+1;
		}
	}
	if(d%n!=0){
		c=d/n+1;
	}
	else{
		c=d/n;
	}
	if(c%2==1){
		r=c-(d%c)+1;
	}
	else{
		r=d%c+1;
	}
	cout<<c<<" "<<r;
	
	return 0;
}
