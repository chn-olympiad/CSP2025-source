#include<iostream>
using namespace std;
int a[105];
int main(){
	long long int n,m,i,j,t,c,h,l;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[j+i-1];
		}
	}
	c=a[1];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[j+i-1]>a[j+i]){
				t=a[j+i];
				a[j+i]=a[j+i-1];
				a[j+i-1]=t;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[j+i-1]==c){
				h=a[j+i-1]/n;
				l=a[j+i-1]%n;		
			}
		}
	}
	cout<<h<<" "<<l;
	return 0;
}

