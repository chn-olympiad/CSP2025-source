#include<iostream>
using namespace std;
int n,m,a[120],r,c,R,R_x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1; i<=nm; i++) cin>>a[i];
	R=a[1];
	for(int i=1; i<nm; i++){
		for(int j=1; j<nm; j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]); 
			}
		}
	}
	for(int i=1; i<=nm; i++){
		if(a[i]==R){
			R_x=i;
		}
	}
	if(R_x%n==0){
		c=R_x/n;
		if(c%2==0) r=1;
		else r=n;
	}
	else{
		c=R_x/n+1;
		if(c%2==0) r=n-R_x%n+1;
		else r=R_x%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
