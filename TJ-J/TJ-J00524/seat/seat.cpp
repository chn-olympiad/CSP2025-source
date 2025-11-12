#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,wei;
	cin>>n>>m;
	int x,p=n*m;
	int a[p],a1;
	for(int i=0;i<p;i++){
		cin>>a[i];
	}
	a1=a[0];
	for(int i=0;i<p;i++){
		for(int z=i+1;z<p;z++){
			if(a[z]>a[i]){
				x=a[z];
				a[z]=a[i];
				a[i]=x;
			}
		}
	}
	for(int i=0;i<p;i++){
		if(a1==a[i])wei=1+i;
	}
	if(wei%n==0){
		if((wei/n)%2==0){
		cout<<wei/n<<" ";
		cout<<1; 
	}else{
		cout<<wei/n<<" ";
		cout<<m;
	}
	}else{
	if((wei/n+1)%2==0){
		cout<<wei/n+1<<" ";
		cout<<m-(wei%n)+1; 
	}else{
		cout<<wei/n+1<<" ";
		cout<<wei%n;
	}
	}
	return 0;
}
