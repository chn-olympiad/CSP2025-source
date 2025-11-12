#include<iostream>
using namespace std;
main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=0,c=0;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	c=a[0];
	for(int i=0;i<m*n;i++){
		for(int j=i+1;j<m*n;j++){
			if(a[i]>a[j]){
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(n==1&&c==a[i]){
			cout<<1<<" "<<i+1;
			break;
		}
		if(m==1&&c==a[i]){
			cout<<i+1<<" "<<1;
			break;
				}
	}
	return 0;
}
