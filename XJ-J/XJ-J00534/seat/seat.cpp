#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,t,x,h,l;
	cin>>n>>m;
	int b=n*m+1;
	int a[b],x;
	for(int o=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<n*m+1;i++){
		if(a[i]<a[i+1]){
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if(i%n!=0){
				l=(i-a[i]%n)/m;
				h=i-n*l;
			}
			else{
				l=i/n;
				h=1;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
