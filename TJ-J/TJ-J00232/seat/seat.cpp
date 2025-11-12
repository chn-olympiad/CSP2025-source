#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int m,n,c=0,r=0,xR=0,p=0;
	cin>>n>>m;
	long long int s=n*m;
	long long int a[s+5]={};
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	xR=a[0];
	sort(a,a+s);
	for(int i=0;i<s;i++){
		if(a[i]==xR){
			p=s-i;
			c=(p-1)/n+1;
		}
	}
	if(c%2==1){
		r=p-(c-1)*n;
	}
	else if(c%2==0){
		r=m-p+(c-1)*n+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0; 
} 
