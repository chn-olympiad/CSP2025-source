#include<bits/stdc++.h>
using namespace std;
int n,m,z,sum,x,y;
int a[102];
int main(){
	freopen("seat.in",stdin);
	freopen("seat.out",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	sum=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]>a[j]){
				z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			sum=i;
			break;
		}
	}
	if(sum%m!=0){
		if(sum/m%2!=0){
			x=sum-sum/m;
		}
		else{
			x=n-sum%m+1;
		}
		if(sum/m!=1){
			y=sum/m-1;
		}
		else{
			y=m;
		}
		
	}
	else if(sum/m!=1){
		if(m%2!=0){
			x=m;
		}
		else{
			x=0;
		}
		y=sum/m;
	}
	else{
		y=m;
	}
	cout << x << " " << y;
	return 0;
}
