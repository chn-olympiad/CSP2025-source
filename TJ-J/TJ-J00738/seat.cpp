#include<iostream>
#include<cmath>
using namespace std;
long long a[10000];
bool cmp(int p,int q){
	return p<q;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>a[i];
	}
	int w=a[1];
	for(int j=0;j<x*y;j++){
		for(int i=0;i<x*y;i++){
			if(a[i]<a[i+1]){
				int r=a[i]; 
				a[i]=a[i+1];
				a[i+1]=r;
			}
		}
	}
	int n;
	for(int i=0;i<x*y;i++){
		if(a[i]==w){
			n=i;
			break;
		}
	}
	int b=n-1/x+1;
	int d=0;
	if(b%2==0){
		d=y-(n-b*(n/b))+1;
	}
	else{
		d=n-b*(n/b);
	}
	cout<<b<<' '<<d; 
	return 0;
}
